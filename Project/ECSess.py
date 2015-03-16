#!/bin/python

from enum import Enum
import sys

class Project:
    def __init__(self, path):
    
class Support(Enum):
    Desktop = 0
    Phone = 1
    Tablet = 3
    
class Action(Enum):
    New = 0
    Build = 1
       
class Commands:
    def __init__(self, argc, argv):
        self.action
        self.support = Support.Desktop
        
 if __name__ == "__main__":
    cmds = Commands(len(sys.argv), sys.argv)
    