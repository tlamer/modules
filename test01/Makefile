# 
# Copyright (C) 2011  Peter Kotvan <peter.kotvan@gmail.com>
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
# 
#
obj-m := test1.o
obj-m += test2.o
obj-m += test3.o
obj-m += chardev.o
obj-m += procfs1.o
obj-m += procfsd2.o
obj-m += procfs2.o
obj-m += procfs3.o
obj-m += check_test.o

EXTRA_CFLAGS := -I$(PWD) -I/usr/include -I/usr/realtime/include

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
