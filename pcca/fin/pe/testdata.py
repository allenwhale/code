import sys
import subprocess as sp
if __name__ == '__main__':
    gen = './' + sys.argv[1].split('.')[0]
    ans = './' + sys.argv[2].split('.')[0]
    sp.call(['g++', '-std=c++11', '-o', gen, sys.argv[1]])
    sp.call(['g++', '-std=c++11', '-o', ans, sys.argv[2]])
    limit = [(5, 10), 
            (5, 100), 
            (5, 1000), 
            (5, 10000), 
            (5, 100000)]
    for (idx, t) in enumerate(limit):
        for i in range(5):
            print(idx, i)
            with open('testdata/%d.%d.in'%(idx, i), 'w+') as f:
                c = sp.Popen([gen, str(i), str(t[0]), str(t[1])], stdout=f)
                c.communicate()
            with open('testdata/%d.%d.out'%(idx, i), 'w+') as f:
                c = sp.Popen([ans,], stdout=f, stdin=open('testdata/%d.%d.in'%(idx, i), 'r'))
                c.communicate()
