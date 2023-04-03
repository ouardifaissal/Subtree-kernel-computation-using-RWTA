import numpy as np
from matplotlib import rc
import matplotlib.pyplot as plt
from scipy.interpolate import spline
from scipy.interpolate import make_interp_spline, BSpline
from matplotlib.ticker import (AutoMinorLocator, MultipleLocator)
import matplotlib.ticker


##################################### Result Files to lists #########################################

with open('DS1') as f:
    lines = f.readlines()
    v = [line.split(':')[0] for line in lines] # Alphabet size
    y = [line.split(':')[1] for line in lines] # number of states
    z = [line.split(':')[2] for line in lines] # Depth
    t = [line.split(':')[3] for line in lines] # kernel value
    k = [line.split(':')[4] for line in lines] # structures construction ( micro s)
    n = [line.split(':')[5] for line in lines] # WA ST kernel computation ( micro s )
    m = [line.split(':')[8] for line in lines] # moschitti ST kernel computation ( micro s )
    x = [line.split(':')[9] for line in lines] # average tree size
    w = [line.strip().split(':')[11] for line in lines] # output degree

#l =[int(p)/int(q) for p,q in zip(x,z)]

with open('DS2') as f:
    lines = f.readlines()
    v2 = [line.split(':')[0] for line in lines] # Alphabet size
    y2 = [line.split(':')[1] for line in lines] # number of states
    z2 = [line.split(':')[2] for line in lines] # Depth
    t2 = [line.split(':')[3] for line in lines] # kernel value
    k2 = [line.split(':')[4] for line in lines] # structures construction ( micro s)
    n2 = [line.split(':')[5] for line in lines] # WA ST kernel computation ( micro s )
    m2 = [line.split(':')[8] for line in lines] # moschitti ST kernel computation ( micro s )
    x2 = [line.split(':')[9] for line in lines] # average tree size
    w2 = [line.strip().split(':')[11] for line in lines] # output degree
with open('DS4') as f:
    lines = f.readlines()
    v3 = [line.split(':')[0] for line in lines] # Alphabet size
    y3 = [line.split(':')[1] for line in lines] # number of states
    z3 = [line.split(':')[2] for line in lines] # Depth
    t3 = [line.split(':')[3] for line in lines] # kernel value
    k3 = [line.split(':')[4] for line in lines] # structures construction ( micro s)
    n3 = [line.split(':')[5] for line in lines] # WA ST kernel computation ( micro s )
    m3 = [line.split(':')[8] for line in lines] # moschitti ST kernel computation ( micro s )
    x3 = [line.split(':')[9] for line in lines] # average tree size
    w3 = [line.strip().split(':')[11] for line in lines] # output degree


###################################################  moschitti versus RWTA #########################################


###################################################  moschitti versus RWTA #########################################

X1 = np.array(x)
Y1 = np.array(y)

X2 = np.array(x2)
Y2 = np.array(y2)

X3 = np.array(x3)
Y3 = np.array(y3)

X = np.array(X3)
Y = np.array(Y3)

fig = plt.figure()
ax = fig.add_subplot(111)
ax.yaxis.set_major_locator(MultipleLocator(500))
ax.yaxis.set_minor_locator(AutoMinorLocator(10))
ax.grid(which='both')
ax.grid(which='major', color='#CCCCCC', linestyle='--')

# An "interface" to matplotlib.axes.Axes.hist() method




plt.bar(X3,[int(y) for y in Y3], align='center', width=0.4, color='#607c8e',alpha=1)


plt.grid(axis='y')
ax.grid(which='major', color='#CCCCCC', linestyle='--')
ax.grid(which='minor', color='#CCCCCC', linestyle=':')
plt.xlabel('Average nodes per tree',fontsize=10)
plt.ylabel('Average number of States',fontsize=10)
#plt.title('Compact representation of ST using RWTA',fontweight='bold')


# Set a clean upper y-axis limit.


plt.savefig('DS4-space.png')
plt.show()


####################################### RWTA versus Moschitti structures constructions #####################################
