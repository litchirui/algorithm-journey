#!/bin/bash

# 读取最新的提交信息或初始化计数器
if [ ! -f day_counter.txt ]; then
    echo "19" > day_counter.txt
fi

# 获取当前的天数
current_day=$(cat day_counter.txt)

# 更新计数器
let current_day+=1
echo $current_day > day_counter.txt

# 执行 git 操作
git status
git add .

# 使用更新后的天数作为提交消息
git commit -m "day_$current_day"

# 推送更改到远程仓库
git push

# 输出当前的天数以便确认
echo "Current day is: $current_day"