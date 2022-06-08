import sys
xmin=float(sys.argv[1])
xmax=float(sys.argv[2])
steps=int(sys.argv[3])
dx=(xmax-xmin)/steps
x=xmin
while x < xmax:
  print(f'{x} {x+dx}')
  x=x+dx