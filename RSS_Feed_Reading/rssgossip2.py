# Copyright (C) 2011 by D+D Griffiths
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

import xml.etree.ElementTree as ET
import os
import requests
import sys
import getopt
import traceback


def usage():
    print("Usage:\npython rssgossip.py [-uh] <search-regexp>")


try:
    opts, args = getopt.getopt(sys.argv[1:], "uh", ["urls", "help"])
    #print(opts)
    
except getopt.GetoptError as err:
    print(str(err))
    usage()
    sys.exit(2)

include_urls = False
for o, a in opts:
    if o == "-u":
        include_urls = True
    elif o in ("-h", "--help"):
        usage()
        sys.exit()
    else:
        assert False, "unhandled option"

#searcher = re.compile(args[0], re.IGNORECASE)
# print(searcher)
for url in (os.environ['RSS_FEED']).split():
    try: 
        headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64; rv:50.0) Gecko/20100101 Firefox/50.0'}
        resp = requests.get(f"{url}", headers=headers)
        root = ET.fromstring(resp.content)
        #print(resp.content)
        for item in root.iter('item'):
            title = item.find('title').text
            link = item.find('link').text            
            if args[0].lower() in title.lower():
                #print("%s" % title)                
                if include_urls:
                    print("\t%s" % link)
        exit(0)
    except Exception as ex:
        """
        # Get current system exception
        ex_type, ex_value, ex_traceback = sys.exc_info()

        # Extract unformatter stack traces as tuples
        trace_back = traceback.extract_tb(ex_traceback)

        # Format stacktrace
        stack_trace = list()

        for trace in trace_back:
            stack_trace.append("File : %s , Line : %d, Func.Name : %s, Message : %s" % (trace[0], trace[1], trace[2], trace[3]))

        print("Exception type : %s " % ex_type.__name__)
        print("Exception message : %s" %ex_value)
        print("Stack trace : %s" %stack_trace)
        """

        print(ex)
        sys.exit(1)
