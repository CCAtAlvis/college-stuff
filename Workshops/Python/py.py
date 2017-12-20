import time
import webbrowser
start_time = time.clock()

new = 1
url = "http://google.com"

webbrowser.open(url, new=new)

print "\n\n"
print "--- %s seconds ---" % (time.clock() - start_time)