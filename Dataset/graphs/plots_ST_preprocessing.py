import numpy as np
from matplotlib import rc
import matplotlib.pyplot as plt
from scipy.interpolate import spline
from scipy.interpolate import make_interp_spline, BSpline
from matplotlib.ticker import (AutoMinorLocator, MultipleLocator)



##################################### Result Files to lists #########################################


with open('results_smola_v1') as f:
    lines = f.readlines()
    x = [line.split(':')[0] for line in lines] # number of nodes
    y = [line.split(':')[1] for line in lines] # number of states
    z = [line.split(':')[2] for line in lines] # level
    t = [line.split(':')[3] for line in lines] # kernel value
    k = [line.split(':')[4] for line in lines] # structures construction ( s)
    n = [line.strip().split(':')[5] for line in lines] # kernel computation ( s )

l =[int(p)/int(q) for p,q in zip(x,z)]

with open('results_optimized_moschitti_v1') as f:
    lines = f.readlines()
    x1 = [line.split(':')[0] for line in lines] # number of nodes
    y1 = [line.split(':')[1] for line in lines] # number of states
    z1 = [line.split(':')[2] for line in lines] # level
    t1 = [line.split(':')[3] for line in lines] # kernel value
    k1 = [line.split(':')[4] for line in lines] # structures construction ( s)
    n1 = [line.strip().split(':')[5] for line in lines] # kernel computation ( s )

l1 =[int(p)/int(q) for p,q in zip(x1,z1)]

with open('optimized_RWTA_v1') as f:
    lines = f.readlines()
    x2 = [line.split(':')[0] for line in lines] # number of nodes
    y2 = [line.split(':')[1] for line in lines] # number of states
    z2 = [line.split(':')[2] for line in lines] # level
    t2 = [line.split(':')[3] for line in lines] # kernel value
    k2 = [line.split(':')[4] for line in lines] # structures construction ( s)
    n2 = [line.strip().split(':')[5] for line in lines] # kernel computation ( s )

l2 =[int(p)/int(q) for p,q in zip(x1,z1)]



###################################################  moschitti versus RWTA #########################################

X = np.array(x)
N = np.array(n)
K = np.array(k)
print min(N)

X1 = np.array(x1)
N1 = np.array(n1)
K1 = np.array(k1)

N2 = np.array(n2)
K2 = np.array(k2)


fig = plt.figure()
ax = fig.add_subplot(111)

x_new = np.linspace(9, 200, 300)
a_BSpline = make_interp_spline(X, K)
y_new = a_BSpline(x_new)

a_BSpline1 = make_interp_spline(X, K1)
y_new1 = a_BSpline1(x_new)

a_BSpline2 = make_interp_spline(X, K2)
y_new2 = a_BSpline2(x_new)

# Change major ticks to show every 20.
ax.xaxis.set_major_locator(MultipleLocator(40))
ax.yaxis.set_major_locator(MultipleLocator(200))

# Change minor ticks to show every 5. (20/4 = 5)
ax.xaxis.set_minor_locator(AutoMinorLocator(4))
ax.yaxis.set_minor_locator(AutoMinorLocator(5))
ax.grid(which='both')
ax.grid(which='major', color='#CCCCCC', linestyle='--')
ax.grid(which='minor', color='#CCCCCC', linestyle=':')


ax.set_title("Structures construction",fontsize=10,fontweight='bold')    
ax.set_xlabel('Number of Tree Nodes',fontsize=10)
ax.set_ylabel('$\mu s$',fontsize=10,fontweight='bold')
#plt.yticks(min(N), max(N), 50)

plt.plot(x_new, y_new2,label='RWTA construction', linestyle='dashed')
plt.plot(x_new, y_new,label='Vishwanathan and Smola\'s construction')
plt.plot(x_new, y_new1,label='Moschitti\'s preprocessing construction')

leg = ax.legend()


 
plt.show()


####################################### RWTA versus Moschitti structures constructions #####################################
