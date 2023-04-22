# awk wirte in cmd
1. easy use 
```shell
awk '{print "hello world" }'
```
this command will wait your console input, each you input, it output is hello word
2. use to print varibale
```shell
echo "yly archlinux" | awk '{print "hello world $1" }'
```
3. set split char
```shell
echo "yly:archlinux" | awk '{print "hello $2" but $1 is NB}'
```
4. run mutiple command 
```shell
echo "yly:archlinux:arcolinux:mipad" | awk '{pirnt "hello world!; print $4}'
```
5. read command from file 
```shell
echo "yly:archlinux:arcolinux:mipad" | awk -F: -f .\first.awk
```
6. ahead data handle run command and behind data handle run command
```shell
echo "yly:archlinux:arcolinux:mipad" | awk -F: 'BEGIN { print "this is some text but print ahead data hanle" } { print "between" $0 } END{print "this is some text but print behind data hanle" }'
```

