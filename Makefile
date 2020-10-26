init:
	find .git/hooks -type l -exec rm {} \;
	find scripts/.githooks -type f -exec ln -sf ../../{} .git/hooks/ \;
	echo "Added githooks"
test:
	cd tests \
	&& python3 test.py
