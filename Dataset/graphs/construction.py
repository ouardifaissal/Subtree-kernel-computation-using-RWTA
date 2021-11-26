import numpy as np
from matplotlib import rc
import matplotlib.pyplot as plt
from scipy.interpolate import spline
from scipy.interpolate import make_interp_spline, BSpline



##################################### Result Files to lists #########################################


with open('results_v1') as f:
    lines = f.readlines()
    x = [line.split(':')[0] for line in lines] # number of nodes
    y = [line.split(':')[1] for line in lines] # number of states
    z = [line.split(':')[2] for line in lines] # level
    t = [line.split(':')[3] for line in lines] # kernel value
    k = [line.split(':')[4] for line in lines] # structures construction ( s)
    n = [line.strip().split(':')[5] for line in lines] # kernel computation ( s )

l =[int(p)/int(q) for p,q in zip(x,z)]

with open('results_moschitti_v2') as f:
    lines = f.readlines()
    x1 = [line.split(':')[0] for line in lines] # number of nodes
    y1 = [line.split(':')[1] for line in lines] # number of states
    z1 = [line.split(':')[2] for line in lines] # level
    t1 = [line.split(':')[3] for line in lines] # kernel value
    k1 = [line.split(':')[4] for line in lines] # structures construction ( s)
    n1 = [line.strip().split(':')[5] for line in lines] # kernel computation ( s )

l1 =[int(p)/int(q) for p,q in zip(x1,z1)]



###################################################  moschitti versus RWTA #########################################

X = np.array(x)

K = np.array(k)
K1 = np.array(k1)


fig = plt.figure()
ax = fig.add_subplot(111)

x_new = np.linspace(9, 200, 300)
a_BSpline = make_interp_spline(X, K)
y_new = a_BSpline(x_new)

a_BSpline1 = make_interp_spline(X, K1)
y_new1 = a_BSpline1(x_new)


ax.set_title("RWTA construction versus Moschitti's preprocessing method",fontsize=10,fontweight='bold')    
ax.set_xlabel('Number of Tree Nodes',fontsize=10)
ax.set_ylabel(' ms',fontsize=10,fontweight='bold')

plt.plot(x_new, y_new,'g',label='RWTA construction')
plt.plot(x_new, y_new1,label='Moschitti\'s preprocessing method')
leg = ax.legend()

plt.grid()

plt.show()


####################################### RWTA versus Moschitti structures constructions #####################################
