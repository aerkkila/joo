installdir = /usr/local/bin

joo: joo.c
	gcc -Wall -Wextra -O2 joo.c -o $@
	if [ ! -e joo.conf ]; then echo $(USER) > joo.conf; fi

install:
	cp joo $(installdir)
	chmod u+s $(installdir)/joo
	if [ ! -e $(installdir)/sudo ]; then ln -s $(installdir)/joo $(installdir)/sudo; fi
	if [ ! -e /etc/joo.conf ]; then if [ -e joo.conf ]; then cp joo.conf /etc; else touch /etc/joo.conf; fi; fi
	chmod 600 /etc/joo.conf

uninstall:
	rm -f $(installdir)/joo /etc/joo.conf
	if [ -L $(installdir)/sudo ]; then rm -v $(installdir)/sudo; fi

clean:
	rm -f joo joo.conf
