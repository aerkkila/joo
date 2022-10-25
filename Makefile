joo: joo.c
	gcc -Wall -Wextra -O2 joo.c -o $@

install:
	cp joo /usr/bin/
	chmod u+s /usr/bin/joo
	if [ ! -e /usr/bin/sudo ]; then ln -s /usr/bin/joo /usr/bin/sudo; fi
	if [ ! -e /etc/joo.conf ]; then if [ -e joo.conf ]; then cp joo.conf /etc; else touch /etc/joo.conf; fi; fi
	chmod 600 /etc/joo.conf

uninstall:
	rm -f /usr/bin/joo /etc/joo.conf
	if [ -L /usr/bin/sudo ]; then rm /usr/bin/sudo; fi
