import urllib
import re
p = re.compile('<\s*script.*?>(.*?)</\s*script\s*>',re.VERBOSE|re.I | re.S)

def extrScript(url):
	f = urllib.urlopen(url)
	s = f.read()
	script = p.findall(s)
	return script


if __name__ == '__main__':
	L = extrScript('http://www.daum.net/')
	for s in L:
		print '//', '-' * 60
		print s
