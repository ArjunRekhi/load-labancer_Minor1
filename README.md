# Development of Load Balancing System using Round Robin Scheduling Algorithm

![Load Balancer Demo Image](https://i0.wp.com/gbhackers.com/wp-content/uploads/2018/12/Load-Balancer.jpg?w=759&ssl=1)

## Problem Statement

* __Performance:__ A machine is bound to perform a certain amount of tasks in a given amount of time.These bounds are increasing exponentially since public’s demand for complicated software is increasing and millions of users strike a website at a single point of time. 
* __Availability:__ Machine can fail anytime. So, avoidance of single point of failure is must. This indicates that you must have replicas. When you have replicas of a server, even if the machine fails, there is not the complete failure of the application. To avoid outages due to hardware failure, we need to run multiple machines, and be able to reroute traffic away from offline systems as fast as possible.
* __Economy:__ We can buy the latest machine to avoid failures and make replicas but there is no certain guarantee that it will not fail and the hardware gets expensive day by day. So, there are some scenarios where vertical scaling is the right choice but for maintaining web application and servers, it is not an economical procurement choice
#     So, the question arises that __“ HOW DO WE SOLVE THESE PROBLEMS” ?__

##Solution

The problem can be solved by the use of a load balancer. Load Balancer sits in front of the servers and routes the client requests across all the server in a efficient and fast manner and ensure that no server overloaded with requests which could degrade our application performance also if a single server goes down load balancer stop sending traffic to that server and redirect traffic to other server which are online.


##Introduction

* A load balancer is a program that will act as an interface between client and server so as to distribute a large number of requests to different servers so that there will be less burden on a single server.
* Client can use the IP address of load balancer to generate a request and load balancer will receive this request.
* Load balancer will go to the corresponding server on behalf of client, will process their requests and will return the output to the client on behalf of the server. 

##Algorithm used:
#ROUND-ROBIN

The round robin algorithm allocates task to the next VM/instance in the queue irrespective of the load on that VM/instance. The Round Robin policy does not consider the resource capabilities, priority, and the length of the tasks. So, the higher priority and the lengthy tasks end up with the higher response times.

##Methodology

We will create an Application Load Balancer program which will balance the incoming user requests across multiple back end servers. It will scan the incoming requests based on the request content and forward the request based on the request type.
For example,if the request coming for the images then the load balancer automatically forward the request to the end point which is serving the images.
The load balancer works on the various algorithm but most commonly used algorithm is round robin algorithm which will forward the request sequentially to the back end server so that all the server have balance load.

##System Requirements
**Software Requirements:**
* Code Editor
* Cloud Resources ( server instance )
* GCC Compiler
* Linux operating system

### How to Use

#Compile
```
gcc -pthread trial3.c -o trial3 -L/usr.include/curl/lib -lcurl
```

#Run 
```
./trial3
```

##References
[1]. https://blog.radware.com/applicationdelivery/2015/11/history-of-the-cloud-pt1/ 
[2]. Kansal N J, Chana I 2012 Cloud Load Balancing Techniques : A Step Towards Green Computing IJCSI Int J Comput Sci Issues [Internet]
[3]. Randles M, Lamb D, Taleb-Bendiab A 2010 A comparative study into distributed load balancing algorithms for cloud computing In: 24th IEEE International Conference on Advanced Information Networking and Applications Workshops, WAINA 2010 p. 551–6
[4]. Aditya A, Chatterjee U, Gupta S 2015 A comparative study of different static and dynamic load balancing algorithm in cloud computing with special emphasis on time factor International Journal of Current Engineering and Technology p. 1898–907
[5]. Mohapatra S, Smruti Rekha K, Mohanty S 2013 A Comparison of Four Popular Heuristics for Load Balancing of Virtual Machines in Cloud Computing International Journal of Computer Applications p. 975–8887
[6]. International Journal "Information Technologies & Knowledge" Volume 9, Number 4, 2015
