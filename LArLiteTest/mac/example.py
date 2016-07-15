import sys
from ROOT import gSystem
gSystem.Load("libgeoalgotester_LArLiteTest")
from ROOT import sample

try:

    print "PyROOT recognized your class %s" % str(sample)

except NameError:

    print "Failed importing LArLiteTest..."

sys.exit(0)

