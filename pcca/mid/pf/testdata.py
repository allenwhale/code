import sys
import subprocess as sp
if __name__ == '__main__':
    gen = './' + sys.argv[1].split('.')[0]
    ans = './' + sys.argv[2].split('.')[0]
    sp.call(['g++', '-std=c++11', '-o', gen, sys.argv[1]])
    sp.call(['g++', '-std=c++11', '-o', ans, sys.argv[2]])
    limit = [(15, 50), 
            (15, 1000), 
            (15, 10000), 
            (15, 50000), 
            (15, 100000)]
    for (idx, t) in enumerate(limit):
        for i in range(5):
            print(idx, i)
            with open('testdata/%d.%d.in'%(idx, i), 'w+') as f:
                c = sp.Popen([gen, str(t[0]), str(t[1]), str(i)], stdout=f)
                c.communicate()
            with open('testdata/%d.%d.out'%(idx, i), 'w+') as f:
                c = sp.Popen([ans,], stdout=f, stdin=open('testdata/%d.%d.in'%(idx, i), 'r'))
                c.communicate()
