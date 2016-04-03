import sys
import subprocess as sp
import os
import difflib

if __name__ == '__main__':
    test = './' + sys.argv[1].split('.')[0]
    sp.call(['g++', '-std=c++11', '-o', test, sys.argv[1]])
    for t in sorted(os.listdir('testdata')):
        if t.count('in'):
            print(t)
            c = sp.Popen(['time', test,], stdin=open('testdata/'+t, 'r'), stdout=open('/tmp/tmp.test', 'w'))
            c.communicate()
            d = difflib.context_diff(open('/tmp/tmp.test', 'r').read(), open('testdata/'+t.replace('in', 'out'), 'r').read())
            print(''.join(d) == '')
