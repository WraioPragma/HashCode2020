import os
import argparse

import toml

def get_settings(filename,forced_choice):
	with open(filename,"r") as f:
		t = toml.load(f)
	settings = t.get("general",{})
	choice = t.get("choice","") if not forced_choice else forced_choice
	settings.update(t.get(choice,{}))
	return settings


def main():
	parser = argparse.ArgumentParser()
	parser.add_argument("--settings")
	parser.add_argument("--choice")
	arguments = parser.parse_args()
	settings = get_settings(arguments.settings,getattr(arguments,"choice",None))
	print(settings)


if __name__ == '__main__':
	main()






