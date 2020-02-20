
def read_file(filename):
	with open(filename,"r") as f:
		s = 	f.read()
	return s

def line_by_line():
	for y in s.splitlines():
		yield s.split()


def read_input(filename):
	p = lambda : line_by_line(read_file(filename))
	b,l,d = [int(x) for x in p()]
	profit = [int(x) for x in p()]
	n = t = m = []
	books = []
	for i in range(0,l):
		n0,t0,m0 = [int(x) for x in p()]
		n.append(n0)
		t.append(t0)
		m.append(m0)
		books.append([int(x) for x in p()])
	return locals()






