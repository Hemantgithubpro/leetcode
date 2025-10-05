
## Initial Thoughts
- The problem seems to find the most occuring integer, then make its copy , swap the most occuring int


### Rough
- a = 0 1 3 3 7 0 , a = 0 0 1 3 3 7
mostoccur='0', needed=4
copying: ops++, replacing: ops+=2, needed-=2
copying: ops++, replacing: ops+=2, needed-=2
needed=0, ops=6

- a = 2 5 7 6 3, a = 2 3 5 6 7
mostoccur='2', needed=4
copying: ops++, replacing: ops+=2, needed-=2

# I need paper for it mannnn.