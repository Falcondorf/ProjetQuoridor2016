#!/bin/bash

git add QuoridorAlexJules
read -p "message de commit: " msg
git commit -m "$msg"
git push
