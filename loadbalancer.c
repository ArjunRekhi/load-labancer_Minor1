#include <curl/curl.h>  
#include <stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h> // for strlen function
#include<unistd.h>	//write

void connect_backend_server(int); 
 char* roundRobin();
void *connection_handler(void *);

// round robin implentation
char* roundRobin(){


if(current_server==1)
 current_server=-1;


  int i=0;

for(i=current_server+1;i<total_server;i++){
// checking if the current server is healthy or not
  if(hc[i]!=0){
    current_server=i;
    break;
}
}

 
struct MemoryStruct {
  char *memory;
	size_t size;
};

char rq[]="http://";
char host[30];

strcpy(host,a[current_server]);

return strcat(rq,host);

}

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb,
		void *userp) {
	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *) userp;

	mem->memory = (char*)realloc(mem->memory, mem->size + realsize + 1);
	if (mem->memory == NULL) {
		/* out of memory! */
		printf("not enough memory (realloc returned NULL)\n");
		return 0;
	}

	memcpy(&(mem->memory[mem->size]), contents, realsize);
	mem->size += realsize;
	mem->memory[mem->size] = 0;

	return realsize;
}


// back end server connection
void connect_backend_server(int client_sd){


  char h[65535];


    memset(h, '\0', sizeof(h));
      read(client_sd , h ,sizeof(h));
        
        fputs(h,stdout);

CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_ALL);

  curl = curl_easy_init();
  if(curl) {


 struct curl_slist *chunk = NULL;

// extrating headers
  

    char *token = strtok(h, "\r\n"); 
     char endpoint[30];
     int k=0;
     while (token != NULL) 
    { 
      printf("%s\n", token); 
      chunk =curl_slist_append(chunk , token);
      if(k==0)
       strcpy(endpoint,token);
      token = strtok(NULL, "\r\n"); 
      k++;
    } 
   
    // extracting endpoint
    k=0;
  token=strtok(endpoint," ");
  while (token != NULL) 
    { 
      printf("%s\n", token); 
      chunk =curl_slist_append(chunk , token);
      if(k==1)
       strcpy(endpoint,token);
      token = strtok(NULL, " "); 
      k++;
    } 



    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
    curl_easy_setopt(curl, CURLOPT_URL, strcat(roundRobin(),endpoint));
    
    
    
    /* always cleanup */
    curl_easy_cleanup(curl);

   curl_slist_free_all(chunk);
  }

  curl_global_cleanup();
 
  // closing client socket
   shutdown(client_sd, SHUT_WR);
   close(client_sd);


}



int main(int argc , char *argv[]){

//creating a socket
int socket_descreptor = socket(AF_INET, SOCK_STREAM, 0);

if( socket_descreptor == -1)
  printf("Could not able to create a socket");


//prepare the socket address in structor

struct sockaddr_in server;

server.sin_family= AF_INET;
server.sin_addr.s_addr= INADDR_ANY;
server.sin_port = htons(5000);


// binding the socket with the port
 if(bind(socket_descreptor,(struct sockaddr *)&server ,sizeof(server))< 0){

         puts("socket bind failed");
         return 1;
  }


  
// listen for the incoming port

listen(socket_descreptor, 5);
puts("listining for the incoming requests");
 

//accepting incoming requests

int c = sizeof( struct sockaddr_in);

int new_socket;
struct sockaddr_in client;

while((new_socket = accept(socket_descreptor ,(struct sockaddr *)&client, (socklen_t *)&c))){
  
      puts("request accepted");

      // connet to the back end server
      connect_backend_server(new_socket);

      
}

return 0;

}
