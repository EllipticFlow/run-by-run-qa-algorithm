
### The way to list all the runs in the badruns_alcache.txt, repeated runs will be in the neighboring lines
cat badruns_allcache.txt | awk '($1+0==$1){print($0)}'  | sort -u | sort -k1,1

### The way to count all the repeated runs
cat badruns_allcache.txt | awk '($1+0==$1){print($0)}'  | sort -k1,1 | uniq -c -w 8
