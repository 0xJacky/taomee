Ŀǰ�������õ�50000000��

1. �ر�ע�������

2. �����ע�����
cp ./usr_id_file ./usr_id_file.bk
cp ./usr_id_idx_file ./usr_id_idx_file.bk
./purge_registered_uid usr_id_file usr_id_idx_file

3. ��ע��ʧ�ܵĺ���ϲ�
./strnum2num32 unreg_id_file unregbin
cat unregbin >> usr_id_file
./gen_usr_id_idx usr_id_file usr_id_idx_file
rm unreg_id_file

4. �����µĿ�ע��źͱ����ţ����б�Ҫ��
./gen_uid 15000000 19999999 reg rres
cat rres >> res

5. ���ɶ�����ע��ţ��ϲ�������ע��������ļ������б�Ҫ��
./strnum2num32 reg regbin
cat regbin >> usr_id_file
./gen_usr_id_idx usr_id_file usr_id_idx_file

6. ���Ҷ�����ע��ţ����б�Ҫ��
./shuffle_uid usr_id_file

7. ����ʱ����ļ������б�Ҫ��
./gen_timestamp_file 70000000 timestamp_file

8. ����ע�������