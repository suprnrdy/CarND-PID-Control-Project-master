import numpy as np
import matplotlib.pyplot as plt

with open("../buildxcode/cte.txt") as f:
    data = f.read()
    
    data = data.split('\n')
    x = [float(i) for i in data]

    
    
    fig = plt.figure()
    ax1 = fig.add_subplot(111)
    ax1.set_title("CTE")
    ax1.set_ylabel('CTE')
    
    
    ax1.plot(x, 'b')
    plt.show()
