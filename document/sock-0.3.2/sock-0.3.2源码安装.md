
## sock-0.3.2源码安装

| author | update |
| ------ | ------ |
| perrynzhou@gmail.com | 2020/10/30 |

- 安装依赖

```
yum install  gcc gdb automake make
```

- 安装

```
$ tar zxvf sock-0.3.2.tar.gz  && cd sock-0.3.2
$ ./autogen.sh 
$ ./configure (with options as needed, try --help)
$ make
$ make install
```

- 使用案例

```
$ whereis sock
sock: /usr/local/bin/sock

//启动一个服务端
$ sock  -s 110.211.55.14 7070

//启动一个客户端
$ sock 10.211.55.14 7070
```
- tcp三次握手和四次挥手
```
$ tcpdump -n -i enp0s5 host 10.211.55.14 and 10.211.55.15

//三次握手
20:31:04.908507 IP 10.211.55.15.37408 > 10.211.55.14.arcp: Flags [S], seq 3206183121, win 29200, options [mss 1460,sackOK,TS val 4235400069 ecr 0,nop,wscale 7], length 0
20:31:04.908585 IP 10.211.55.14.arcp > 10.211.55.15.37408: Flags [S.], seq 377079936, ack 3206183122, win 28960, options [mss 1460,sackOK,TS val 508436757 ecr 4235400069,nop,wscale 7], length 0
20:31:04.908730 IP 10.211.55.15.37408 > 10.211.55.14.arcp: Flags [.], ack 1, win 229, options [nop,nop,TS val 4235400069 ecr 508436757], length 0

//四次挥手
20:32:10.588900 IP 10.211.55.15.37408 > 10.211.55.14.arcp: Flags [F.], seq 1, ack 1, win 229, options [nop,nop,TS val 4235465750 ecr 508436757], length 0
20:32:10.589032 IP 10.211.55.14.arcp > 10.211.55.15.37408: Flags [F.], seq 1, ack 2, win 227, options [nop,nop,TS val 508502438 ecr 4235465750], length 0
20:32:10.589099 IP 10.211.55.15.37408 > 10.211.55.14.arcp: Flags [.], ack 2, win 229, options [nop,nop,TS val 4235465750 ecr 508502438], length 0
```
- sock使用说明

```
$ sock
usage: sock [ options ] <host> <port>              (for client; default)
       sock [ options ] -s [ <IPaddr> ] <port>     (for server)
       sock [ options ] -i <host> <port>           (for "source" client)
       sock [ options ] -i -s [ <IPaddr> ] <port>  (for "sink" server)
options: -b n  bind n as client's local port number
         -c    convert newline to CR/LF & vice versa
         -f a.b.c.d.p  foreign IP address = a.b.c.d, foreign port# = p
         -g a.b.c.d  loose source route
         -h    issue TCP half close on standard input EOF
         -i    "source" data to socket, "sink" data from socket (w/-s)
         -j a.b.c.d  join multicast group
         -k    write or writev in chunks
         -l a.b.c.d.p  client's local IP address = a.b.c.d, local port# = p
         -n n  #buffers to write for "source" client (default 1024)
         -o    do NOT connect UDP client
         -p n  #ms to pause before each read or write (source/sink)
         -q n  size of listen queue for TCP server (default 5)
         -r n  #bytes per read() for "sink" server (default 1024)
         -s    operate as server instead of client
         -t n  set multicast ttl
         -u    use UDP instead of TCP
         -v    verbose
         -w n  #bytes per write() for "source" client (default 1024)
         -x n  #ms for SO_RCVTIMEO (receive timeout)
         -y n  #ms for SO_SNDTIMEO (send timeout)
         -A    SO_REUSEADDR option
         -B    SO_BROADCAST option
         -C    set terminal to cbreak mode
         -D    SO_DEBUG option
         -E    IP_RECVDSTADDR option
         -F    fork after connection accepted (TCP concurrent server)
         -G a.b.c.d  strict source route
         -H n  IP_TOS option (16=min del, 8=max thru, 4=max rel, 2=min$)
         -I    SIGIO signal
         -J n  IP_TTL option
         -K    SO_KEEPALIVE option
         -L n  SO_LINGER option, n = linger time
         -N    TCP_NODELAY option
         -O n  #ms to pause after listen, but before first accept
         -P n  #ms to pause before first read or write (source/sink)
         -Q n  #ms to pause after receiving FIN, but before close
         -R n  SO_RCVBUF option
         -S n  SO_SNDBUF option
         -T    SO_REUSEPORT option
         -U n  enter urgent mode before write number n (source only)
         -V    use writev() instead of write(); enables -k too
         -W    ignore write errors for sink client
         -X n  TCP_MAXSEG option (set MSS)
         -Y    SO_DONTROUTE option
         -Z    MSG_PEEK

```

  