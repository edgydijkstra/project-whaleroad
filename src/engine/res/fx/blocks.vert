			layout(location = 0) in highp uint L1;
			layout(location = 1) in highp uint L2;
			layout(location = 2) in vec3 pos;
			layout(location = 3) in vec2 uv;
			layout(location = 4) in uint face_index;
			layout(location = 5) in uint face_neighbor1;
			layout(location = 6) in uint face_neighbor2;
			uniform int x0,y0;
			
uniform sampler2D shadowmap0;
uniform sampler2D shadowmap1;
uniform sampler2D shadowmap2;
uniform sampler2D shadowmap3;
uniform sampler2D shadowmap4;
uniform sampler2D shadowmap5;
uniform sampler2D shadowmap6;
uniform sampler2D shadowmap7;
/* 
  uint32_t L1u = uint32_t(z2%65536) +
                (uint32_t(xydiff) << 16uL) + (uint32_t(which%256) << 24uL);
  uint32_t L2u = uint32_t(which/256) + uint32_t(L1+L2<<4uL+L3<<8uL+L4<<12uL+L5<<16uL+L6<<20uL)<<8uL;
  */
			out vec3 col;
			out vec2 coord;
			out vec2 zw;
			 vec4 p;
			 out float shadow;
			uniform mat4x4 projection, view;
			
			uniform mat4x4 light_projection;
			uniform mat4x4 light_view;
			uniform vec3 sun_color;
			
            void main(){
                
				int L1x=(int(L2>>8u)>>(4*int(face_index)))%16;
				int L1y=(int(L2>>8u)>>(4*int(face_neighbor1)))%16;
				int L1z=(int(L2>>8u)>>(4*int(face_neighbor2)))%16;
				uint xydiff=(uint(L1)>>16u)&0xffu;
				
				ivec3 positioni=ivec3(int(xydiff)/16+x0,int(xydiff)%16+y0,int(L1%16384u)); 
								
				vec3 position=vec3(float(positioni.x),float(positioni.y),float(positioni.z))+pos;
				
				uint which=uint(L1>>24u)&0xffu+(uint(L2&0xffu)<<8u);
				coord=uv+vec2(float(which%256u)/256.0,0.0);
				vec4 vpos=projection*view*vec4(position.xyz,1.0);
				zw=vpos.zw;
				
				float Lr=float(L1x+L1y+L1z)/45.0;
				col=Lr*sun_color;
				p=light_projection*light_view*vec4(position,1.0);
				 vec4 ShadowCoordPostW = p / p.w;
                float zmax=1.0;
                float zs=zmax/8.0;
                ShadowCoordPostW = ShadowCoordPostW * 0.5 + 0.5; 
                float z=ShadowCoordPostW.z;
                float z2=zmax;
                if(z<zs){
                    z2=texture(shadowmap0,ShadowCoordPostW.xy).r/8.0;
                }
                
                else if(z<zs*2.0){
                    z2=texture(shadowmap1,ShadowCoordPostW.xy).r/8.0+zs;
                }
                
                else if(z<zs*3.0){
                    z2=texture(shadowmap2,ShadowCoordPostW.xy).r/8.0+zs*2.0;
                }
                
                else if(z<zs*4.0){
                    z2=texture(shadowmap3,ShadowCoordPostW.xy).r/8.0+zs*3.0;
                }
                
                else if(z<zs*5.0){
                    z2=texture(shadowmap4,ShadowCoordPostW.xy).r/8.0+zs*4.0;
                }
                
                else if(z<zs*6.0){
                    z2=texture(shadowmap5,ShadowCoordPostW.xy).r/8.0+zs*5.0;
                }
                
                else if(z<zs*7.0){
                    z2=texture(shadowmap6,ShadowCoordPostW.xy).r/8.0+zs*6.0;
                }
                
                else if(z<zs*8.0){
                    z2=texture(shadowmap7,ShadowCoordPostW.xy).r/8.0+zs*7.0;
                }
                shadow = float(z2>0.999999*ShadowCoordPostW.z);
				gl_Position=vpos;
			}    
