#!/bin/bash

# ��ȡ���µ��ύ��Ϣ���ʼ��������
if [ ! -f day_counter.txt ]; then
    echo "19" > day_counter.txt
fi

# ��ȡ��ǰ������
current_day=$(cat day_counter.txt)

# ���¼�����
let current_day+=1
echo $current_day > day_counter.txt

# ִ�� git ����
git status
git add .

# ʹ�ø��º��������Ϊ�ύ��Ϣ
git commit -m "day_$current_day"

# ���͸��ĵ�Զ�ֿ̲�
git push

# �����ǰ�������Ա�ȷ��
echo "Current day is: $current_day"