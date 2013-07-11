import re
import json
import sys

f=open(sys.argv[1])
hfile=f.read()
f.close()

kmapd={}
for i in hfile.split('\n'):
	if len(i) > 8:
		key_name,vals = i.split('//',1)
		key_name = key_name.replace(',','').strip()
		keys,keysym = vals.split('  ',1)
		keysym, comment = (keysym+' ').split(' ',1)
		keys = re.sub('''[A-Z]''','0',keys.replace(' ','').replace('-','1'))
		kmapd.update({keys:{'keys':[int(x) for x in list(keys)],'keysym':keysym,'name':key_name,'comment':comment}})

f=open(sys.argv[1]+'.json','w')
f.write(json.dumps(kmapd))
f.close()
print(sys.argv[1]+'.json')
		
