# 
# Pcan communication driver
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

define make-all
@cd test01; make; cd ../rtdm_pcan; make; cd ..
endef

define make-clean
@cd test01; make clean; cd ../rtdm_pcan; make clean; cd ..
endef

all:
	$(make-all)

clean:
	$(make-clean)
