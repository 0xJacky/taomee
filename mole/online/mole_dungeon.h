#ifndef MOLE_DUNGEON_H
#define MOLE_DUNGEON_H

#define DUNGEON_MAX_AWARD_KIND			16
#define DUNGEON_MAX_AWARD_ITEM_KIND		8
#define DUNGEON_MAX_REGION_KIND			8
#define DUNGEON_MAX_RANDOM_TABLE_NUM	10

#define DUNGEON_MAP_MAX_SIZE 			3
#define DUNGEON_MAP_MAX_MINE_KIND 		256
#define DUNGEON_MAP_MAX_EVENT_KIND 		256
#define DUNGEON_MAP_MAX_BOSS_KIND 		256
#define DUNGEON_MAP_MAX_TRIGGER_KIND 	256




//back from db
typedef struct explore_begin_info_s
{
	uint32_t 	map_id;
	uint32_t	screen_id;
	uint32_t 	hp;
	uint32_t	time_surplus;
	uint32_t 	exp;
	uint32_t	explore_counter;
}__attribute__((packed)) explore_begin_info_t;

//������Ʒ��Ϣ
typedef struct award_item_info_s
{
	uint32_t item_id;
	uint32_t item_count;
} __attribute__((packed)) award_item_info_t;
//���ɵ�����Ϣ����
typedef struct award_info_s
{
	uint32_t item_kind;
	uint32_t rate;
	award_item_info_t item_info[DUNGEON_MAX_AWARD_ITEM_KIND];
} __attribute__((packed)) award_info_t;
//���ɽ׶�����
typedef struct explore_region_s
{
	uint32_t award_kind;
	uint32_t max_explore_count;
	award_info_t award_info[DUNGEON_MAX_AWARD_KIND];
} __attribute__((packed)) explore_region_t;
//����Ԫ��ö��
enum ELEMENT_TYPE
{
	ET_GAP		= 0,
	ET_MINE,
	ET_BOSS,
	ET_EVENT,
	ET_TRIGGER,
	ET_FORCE_DWORD = 0xffffffff,
};
//�������
typedef struct mine_info_s
{
	uint32_t exp_inc;
	uint32_t hp_consum;
	uint32_t region_kind;
	uint32_t max_count;
	uint32_t max_explore_times;
	explore_region_t region_info[DUNGEON_MAX_REGION_KIND];
} __attribute__((packed)) mine_info_t;
//BOSS����
typedef struct boss_info_s
{
	uint32_t exp_inc;
	uint32_t hp_consum;
	uint32_t max_explore_times;
} __attribute__((packed)) boss_info_t;
//�¼�����
typedef struct event_info_s
{
	uint32_t exp_inc;
	uint32_t hp_consum;
	uint32_t max_explore_times;
	uint32_t award_kind;
	award_info_t award_info[DUNGEON_MAX_AWARD_KIND];
} __attribute__((packed)) event_info_t;
//��������
typedef struct trigger_info_s
{
	uint32_t exp_inc;
	uint32_t hp_consum;
	uint32_t max_count;
	uint32_t max_explore_times;
} __attribute__((packed)) trigger_info_t;
//����������Ϣ
typedef struct area_info_s
{
	uint32_t area_type;
	uint32_t element_id;
	int	 	 rand_table;
	uint32_t rate;
} __attribute__((packed)) area_info_t;
//����ھ��ÿ�����������
typedef struct element_limit_s
{
	uint32_t mine;
	uint32_t boss;
	uint32_t event;
	uint32_t trigger;
} __attribute__((packed)) element_limit_t;

//������Ϣ
typedef struct dungeon_screen_info_s
{
	uint32_t map_id;											//ʵ�ʽ���ĵ�ͼID
	uint32_t area_count;
	area_info_t area_info[DUNGEON_MAX_MAP_AREA_NUM];
	uint32_t rand_table_count;
	uint32_t rand_table[DUNGEON_MAX_RANDOM_TABLE_NUM];			//���λ����ĳ�Ա��Ŀ
} __attribute__((packed)) dungeon_screen_info_t;
//��ͼ��Ϣ
typedef struct dungeon_map_info_s
{
	uint32_t screen_count;
	dungeon_screen_info_t screen_info[DUNGEON_MAX_SCREEN_NUM];
	element_limit_t random_element_limit;
} __attribute__((packed)) dungeon_map_info_t;
//��ͼ����
typedef struct dungeon_all_map_info_s
{
	uint32_t map_count;
	dungeon_map_info_t map_info[DUNGEON_MAP_MAX_SIZE];
} __attribute__((packed)) dungeon_all_map_info_t;
//�������
typedef struct dungeon_all_mine_info_s
{
	uint32_t kind;
	mine_info_t	info[DUNGEON_MAP_MAX_MINE_KIND];
} __attribute__((packed)) dungeon_all_mine_info_t;
//BOSS����
typedef struct dungeon_all_boss_info_s
{
	uint32_t kind;
	boss_info_t	info[DUNGEON_MAP_MAX_BOSS_KIND];
} __attribute__((packed)) dungeon_all_boss_info_t;
//�¼�����
typedef struct dungeon_all_event_info_s
{
	uint32_t kind;
	event_info_t info[DUNGEON_MAP_MAX_EVENT_KIND];
} __attribute__((packed)) dungeon_all_event_info_t;
//��������
typedef struct dungeon_all_trigger_info_s
{
	uint32_t kind;
	trigger_info_t info[DUNGEON_MAP_MAX_TRIGGER_KIND];
} __attribute__((packed)) dungeon_all_trigger_info_t;

//�����ڱ��������ȼ�
uint32_t dungeon_get_level_by_exp(uint32_t exp);


//��ʼ̽��
int	dungeon_begin_explore_cmd(sprite_t* p, const uint8_t* body, int len);
int	dungeon_begin_explore_callback(sprite_t* p, uint32_t id, char* buf, int len);
int dungeon_begin_explore_send_result(sprite_t* p);
//��ȡ̽�ձ�����Ϣ
int dungeon_get_bag_info_cmd(sprite_t* p, const uint8_t* body, int len);
int dungeon_get_bag_info_callback(sprite_t* p, uint32_t id, char* buf, int len);
//̽���ƶ�����
int dungeon_explore_area_cmd(sprite_t* p, const uint8_t* body, int len);
int dungeon_explore_mine(sprite_t* p, uint32_t element_id, uint32_t area_id);
int dungeon_explore_boss(sprite_t* p, uint32_t element_id, uint32_t area_id);
int dungeon_explore_event(sprite_t* p, uint32_t element_id, uint32_t area_id);
int dungeon_explore_trigger(sprite_t* p, uint32_t element_id, uint32_t area_id);
//��ǰ�˷��ؿ��ɺ������
int dungeon_explore_area_send_result(sprite_t* p, award_info_t* award, uint32_t area_id, uint32_t exp_inc, uint32_t hp_consum);
//this command dosn't need communicate with db

//ͬ��Ѫ��
int dungeon_syn_hp_cmd(sprite_t* p, const uint8_t* body, int len);

// ʰȡ����
int dungeon_pick_item_cmd(sprite_t* p, const uint8_t* body, int len);
//needn't communicate with db
//ʹ�õ���
int dungeon_use_item_cmd(sprite_t* p, const uint8_t* body, int len);
int dungeon_use_item_callback(sprite_t* p, uint32_t id, char* buf, int len);
//����̽��
int	dungeon_end_explore_cmd(sprite_t* p, const uint8_t* body, int len);
// needn't communicate with db
//���������ļ�
int dungeon_load_all_map_info();
int dungeon_load_map_info(char* file, dungeon_map_info_t* map_info);
int dungeon_load_map_element(char* file);
int dungeon_parse_mine_info(xmlNodePtr ptr, dungeon_all_mine_info_t* mine_info);
int dungeon_parse_boss_info(xmlNodePtr ptr, dungeon_all_boss_info_t* boss_info);
int dungeon_parse_event_info(xmlNodePtr ptr, dungeon_all_event_info_t* event_info);
int dungeon_parse_trigger_info(xmlNodePtr ptr, dungeon_all_trigger_info_t* trigger_info);

//�䱦�ⲿ��
//��ȡչ̨��Ϣ
int dungeon_get_exhibit_info_cmd(sprite_t* p, const uint8_t* body, int len);
int dungeon_get_exhibit_info_callback(sprite_t* p, uint32_t id, char* buf, int len);
//��ȡ�ֿ���Ϣ
int dungeon_get_storage_info_cmd(sprite_t* p, const uint8_t* body, int len);
int dungeon_get_storage_info_callback(sprite_t* p, uint32_t id, char* buf, int len);
//��ȡ������Ϣ
int dungeon_get_friend_info_cmd(sprite_t* p, const uint8_t* body, int len);
int dungeon_get_friend_info_callback(sprite_t* p, uint32_t id, char* buf, int len);
//��ȡ�ÿ���Ϣ
int dungeon_get_visitor_info_cmd(sprite_t* p, const uint8_t* body, int len);
int dungeon_get_visitor_info_callback(sprite_t* p, uint32_t id, char* buf, int len);

//�ÿͼ�¼
inline int dungeon_add_exhibit_visitors(sprite_t *p, userid_t id);
inline int dungeon_commit_level_to_db(sprite_t* p, uint32_t level);

//��ȫ��db���طÿ͵ȼ���Ϣ
int dungeon_get_visitor_full_info_callback(sprite_t* p, uint32_t id, char* buf, int len);

//��������
int dungeon_set_background_map_cmd(sprite_t* p, const uint8_t* body, int len);
int dungeon_set_background_map_callback(sprite_t* p, uint32_t id, char* buf, int len);
//�趨չʾ��Ʒ
int dungeon_set_exhibit_item_cmd(sprite_t* p, const uint8_t* body, int len);
int dungeon_set_exhibit_item_callback(sprite_t* p, uint32_t id, char* buf, int len);
//����չ̨����Ʒ
int dungeon_swap_exhibit_item_cmd(sprite_t* p, const uint8_t* body, int len);
int dungeon_swap_exhibit_item_callback(sprite_t* p, uint32_t id, char* buf, int len);
//�任չʾƷչʾ��λ
int dungeon_set_exhibit_state_cmd(sprite_t* p, const uint8_t* body, int len);
int dungeon_set_exhibit_state_callback(sprite_t* p, uint32_t id, char* buf, int len);


extern dungeon_all_map_info_t dungeon_map_info;
#endif

