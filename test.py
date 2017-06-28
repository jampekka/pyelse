import pyelse
import matplotlib.pyplot as plt
import sys
import numpy as np

img = plt.imread(sys.argv[1])
img = np.mean(img, axis=2)
img = (img*255).astype(np.uint8)

ret = pyelse.run(img)
x = ret.center.x
y = ret.center.y
plt.imshow(img, cmap='gray')
plt.plot(x, y, 'o', color='red')
plt.show()

