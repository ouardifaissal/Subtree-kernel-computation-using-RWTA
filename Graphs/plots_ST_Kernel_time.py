import numpy as np
from matplotlib import rc
import matplotlib.pyplot as plt
from scipy.interpolate import spline
from scipy.interpolate import make_interp_spline, BSpline
from matplotlib.ticker import (AutoMinorLocator, MultipleLocator)



##################################### Result Files to lists #########################################

with open('DS4') as f:
    lines = f.readlines()
    v = [line.split(':')[0] for line in lines] # Alphabet size
    y = [line.split(':')[1] for line in lines] # number of states
    z = [line.split(':')[2] for line in lines] # Depth
    t = [line.split(':')[3] for line in lines] # kernel value
    k = [line.split(':')[4] for line in lines] # structures construction ( micro s)
    n = [line.split(':')[5] for line in lines] # WA ST kernel computation ( milli s )
    m = [line.split(':')[8] for line in lines] # moschitti ST kernel computation ( milli s )
    x = [line.split(':')[9] for line in lines] # average tree size
    w = [line.strip().split(':')[11] for line in lines] # output degree

#l =[int(p)/int(q) for p,q in zip(x,z)]




###################################################  moschitti versus RWTA #########################################

X = np.array(x)
N = np.array(n)
M = np.array(m)


fig = plt.figure()
ax = fig.add_subplot(111)

x_new = np.linspace(5, 30000, 5000)
a_BSpline = make_interp_spline(X, N)
y_new = a_BSpline(x_new)

a_BSpline1 = make_interp_spline(X, M)
y_new1 = a_BSpline1(x_new)

x1 = np.arange(5, 35000, 5000)
y1 = [nn*np.log(nn)/3000 for nn in x1]
y2 = [(nn)/1000 for nn in x1]


# Change major ticks to show every 20.
ax.xaxis.set_major_locator(MultipleLocator(5000))
ax.yaxis.set_major_locator(MultipleLocator(10))

# Change minor ticks to show every 5. (20/4 = 5)
ax.xaxis.set_minor_locator(AutoMinorLocator(5))
ax.yaxis.set_minor_locator(AutoMinorLocator(5))
ax.grid(which='both')
ax.grid(which='major', color='#CCCCCC', linestyle='--')
ax.grid(which='minor', color='#CCCCCC', linestyle=':')


ax.set_xlabel('Average nodes per tree',fontsize=10)
ax.set_ylabel('$Milliseconds$',fontsize=10)
#plt.yticks(min(N), max(N), 50)

plt.plot(x_new, y_new,label='RWTA based ST kernel')

plt.plot(x_new, y_new1,label='Moschitti\'s method')

plt.plot(x1,y1,label="n/3*log(n)", linestyle='dotted')
plt.plot(x1,y2,label="n",linestyle='dotted')


leg = ax.legend(prop={"size":8})


plt.savefig('DS4.png')
plt.show()


####################################### RWTA versus Moschitti structures constructions #####################################
