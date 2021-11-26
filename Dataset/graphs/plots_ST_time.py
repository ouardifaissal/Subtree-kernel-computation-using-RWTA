import numpy as np
from matplotlib import rc
import matplotlib.pyplot as plt
from scipy.interpolate import spline
from scipy.interpolate import make_interp_spline, BSpline
from matplotlib.ticker import (AutoMinorLocator, MultipleLocator)



##################################### Result Files to lists #########################################

with open('RWTA_vs_aioli_4') as f:
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




###################################################  moschitti versus RWTA #########################################

X = np.array(x)
N = np.array(n)
M = np.array(m)




fig = plt.figure()
ax = fig.add_subplot(111)

x_new = np.linspace(5, 500, 100)
a_BSpline = make_interp_spline(X, N)
y_new = a_BSpline(x_new)

a_BSpline1 = make_interp_spline(X, M)
y_new1 = a_BSpline1(x_new)


# Change major ticks to show every 20.
ax.xaxis.set_major_locator(MultipleLocator(100))
ax.yaxis.set_major_locator(MultipleLocator(100))

# Change minor ticks to show every 5. (20/4 = 5)
ax.xaxis.set_minor_locator(AutoMinorLocator(4))
ax.yaxis.set_minor_locator(AutoMinorLocator(5))
ax.grid(which='both')
ax.grid(which='major', color='#CCCCCC', linestyle='--')
ax.grid(which='minor', color='#CCCCCC', linestyle=':')


ax.set_xlabel('Average nodes per tree',fontsize=10)
ax.set_ylabel('$Microseconds$',fontsize=10)
#plt.yticks(min(N), max(N), 50)

plt.plot(x_new, y_new,label='RWTA based ST kernel', linestyle='dashed')
#plt.plot(x_new, y_new,label='Vishwanathan and Smola\'s method')
plt.plot(x_new, y_new1,label='Moschitti\'s method')

leg = ax.legend(prop={"size":8})


plt.savefig('n5-500.png')
plt.show()


####################################### RWTA versus Moschitti structures constructions #####################################
