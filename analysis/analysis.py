import os
import argparse

import toml
from common import *
from generic import *


methods = {
	"basic" : basic,
}


def get_settings(filename,forced_choice = ""):
	with open(filename,"r") as f:
		t = toml.load(f)
	settings = t.get("general",{})
	choice = t.get("choice","") if not forced_choice else forced_choice
	settings.update(t.get(choice,{}))
	return settings


def main():
	settings_file = "settings.toml"
	settings = get_settings(settings_file)
	print(settings)
	input_files = {x:read_input("../input/" + x + ".txt") for x in settings["input"]}
	# for s in settings["methods"]:
	# 	for file in input_files:
	# 		methods[s]()



filenames = [""]




if __name__ == '__main__':
	main()






