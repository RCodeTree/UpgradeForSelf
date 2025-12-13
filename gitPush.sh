#!/bin/bash

# 先清除编译后的可执行文件
echo "正在清除编译后的可执行文件..."
rm -f *.exe *.out

# 先从各个远程仓库拉取最新代码
echo "正在从所有远程仓库拉取最新代码..."

# 拉取GitHub main分支，添加错误处理
if git pull origin main; then
    echo "❤ ❤ ❤已经从origin/main拉取最新代码❤ ❤ ❤"
else
    echo "⚠️ 从origin/main拉取代码失败，脚本停止运行"
    # 睡眠3秒
    sleep 3
    exit 1
fi

# 拉取Gitee master分支，添加错误处理
if git pull gitee master; then
    echo "❤ ❤ ❤已经从gitee/master拉取最新代码❤ ❤ ❤"
else
    echo "⚠️ 从gitee/master拉取代码失败，脚本停止运行"
    # 睡眠3秒
    sleep 3
    exit 1
fi

# 获取用户提交信息
read -p "请输入提交信息：" commit_message

# 获取当前分支
current_branch=$(git branch --show-current)

if [ "$current_branch" = "main" ]; then # 如果当前分支是main
    # 先提交并推送main分支到GitHub
    git add .
    echo "正在提交并推送main分支到GitHub..."
    git commit -m "$commit_message"
    git push origin main

    # 再切换到master分支并合并main分支，再进行推送到Gitee
    if git checkout master; then
        git merge main
        echo "正在推送master分支到Gitee..."
        git push gitee master
    else
        echo "⚠️ master分支不存在，请及时处理"
        # 睡眠3秒
        sleep 3
        exit 1
    fi

    # 切换回master分支
    git checkout master
    echo "❤ ❤ ❤已经切换回到master分支❤ ❤ ❤"

elif [ "$current_branch" = "master" ]; then # 如果当前分支是master
    # 先提交并推送master分支到Gitee
    git add .
    echo "正在提交并推送master分支到Gitee..."
    git commit -m "$commit_message"
    git push gitee master

    # 再切换到main分支并合并master分支，再进行推送到GitHub
    if git checkout main; then
        git merge master
        echo "正在推送main分支到GitHub..."
        git push origin main
    else
        echo "⚠️ main分支不存在，请及时处理"
        # 睡眠3秒
        sleep 3
        exit 1
    fi

    # 切换回master分支
    git checkout master
    echo "❤ ❤ ❤已经切换回到master分支❤ ❤ ❤"

else # 如果当前分支不是main或master，提示错误
    echo "❤ ❤ ❤当前分支不是main或master❤ ❤ ❤"
fi
