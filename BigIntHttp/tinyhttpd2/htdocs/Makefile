all:login.cgi reg.cgi

login.cgi:login.cpp
	g++ -o login.cgi login.cpp -g `mysql_config --cflags --libs`
reg.cgi:reg.cpp
	g++ -o reg.cgi reg.cpp -g `mysql_config --cflags --libs`
clean:
	rm reg.cgi login.cgi
