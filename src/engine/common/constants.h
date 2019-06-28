#pragma once
namespace constants {
constexpr const  int WORLD_HEIGHT = 100;
constexpr const  int UDP_MTU = 576; 
constexpr const  int MAX_IP_HEADER_SIZE = 60;
constexpr const  int UDP_HEADER_SIZE = 8;
constexpr const  int MAX_DATAGRAM_SIZE =
    UDP_MTU - MAX_IP_HEADER_SIZE - UDP_HEADER_SIZE;
constexpr const  int CHUNK_WIDTH = 16;
constexpr const  int CHUNK_HEIGHT = 20;
constexpr const  int MAX_RESIDENT_PAGES=128;
constexpr const  int PAGE_DIM=128;       
constexpr const  int LIGHT_COMPONENTS=12;  
constexpr const unsigned long long PAGE_RAM=PAGE_DIM*PAGE_DIM*(LIGHT_COMPONENTS*WORLD_HEIGHT*1+WORLD_HEIGHT*2*2+2)+(PAGE_DIM*PAGE_DIM)/32*8;
                                                        //light                                    //blocks,invisible_blocks    //dirty_list   //zmap
constexpr const  unsigned long long ALL_PAGES_RAM=MAX_RESIDENT_PAGES*PAGE_RAM;
constexpr const int MAX_CONCURRENCY=4;
constexpr const  int INVERSE_COMPONENTS[]={1,0,3,2,5,4};        
constexpr const  float LPV_WEIGHT[]={
    -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -2, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, 1, 0, -1, 1, 0, -1, 1, 0, -1, 1, 0, -1, 1, 0, -2, 1, 0, -1, 1, 0, -1, 1, 0, -1, 1, 0, -1, -1, -1, -1, 0, 0, 0, 1, 1, 1, -1, -2, -1, 0, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, -1, -1, -1, 1, 1, 1, 0, 0, 0, -1, -2, -1, 1, 1, 1, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -2, -1, -1, -1, -1};
    constexpr const  float LPV_BIAS[]={0.001,0.3,0.3,0.3,0.3,0.3};
} // namespace constants
    
