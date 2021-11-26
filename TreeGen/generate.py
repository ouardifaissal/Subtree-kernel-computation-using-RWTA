import  tree_kernels 
import time
import  timing
import tree 
#lambda # kernel parameter 

dat1 = tree.Dataset() 

f1 = open('./Dataset/Results/h5_o5_a50','a')

T1 = tree.RandomTreesPowerLawDistribution(5,0.3,5,50)

dat1.generateRandomDataset(T1,100)


dat1.getStats()

f1.write(dat1.getStats() + "\n")

dat1.printToFile('./Dataset/h5_o5_a50.txt')

k = tree_kernels.KernelST(1) 
k.printKernelEvaluation(dat1,f1)




