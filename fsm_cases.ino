------------------       function for going from forward node to node    ---------------------*/


/*
* Function Name:fwd_node_2_node
* Input: Initial state 
* Output: No ne
* Logic:implementation for bot traversal from one node to other.
* Example call : fwd_node_2_node( state )
/*
/*###############################################################################################
 #################################################################################################
 

int fwd_node_2_node(int state  )
{
  fwd_go = 11;
  flag_fwd = 0 ;
  while(flag_fwd != 3)
  { 
    sensor_data();

    if (flag_fwd == 0)
    {

      if ((left >= 1 && center >= 1 && right == 0) || (left == 0 && center >= 1 && right >= 1) || (left >=1  && center >= 1 && right >= 1)  )
      { //current_time = millis();
        //while((millis()<current_time+15))
        {
        flag_fwd = 1;
        state = 11;
        cases(state); 
      }      
      }   
    }
    else if (flag_fwd == 1)
    {
      if( state == 11)
      {
        if(left == 0 && center >= 3 && right == 0)
        {
          flag_fwd =2;
          state = 11;//fordward
          cases(state);

        }     
        else if(left >= 1 && center >= 1 && right >= 1)
        {
          state = 11;//fordward
          cases(state);        
        }
        else if((left >= 2 && center >= 3 && right == 0) || (left >= 3 && center == 0 && right == 0))
        {
          state = 10;//left
          cases(state);

        }
        else if((left == 0 && center >= 1 && right >= 1) || (left == 0 && center == 0 && right >= 1)) 
        {
          state = 01;//right
          cases(state);
        } 
      }     

      else if (state == 01)
      {
        if(left == 0 && center >= 2 && right == 0)
        {
          flag_fwd =2;
          state = 11;
          cases(state);

        }     
        else if(left == 1 && center >= 2 && right == 1)
        {
          state = 11;
          cases(state);
        }
        else if((left >= 2 && center >= 2 && right == 0) || (left >= 3 && center == 0 && right == 0))
        {
          state = 10;//left
          cases(state);
        }  
      }      
      else  if (state == 10)
      {
        if(left == 0 && center >= 1 && right == 0)
        {
          flag_fwd =2;
          state = 11;
          cases(state); 
        }      
        else if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if((left == 0 && center >= 1 && right >= 1) || (left == 0 && center == 0 && right >= 1)) 
        {
          state = 01;//right
          cases(state);
        }  
      }
    }
    //follow straight line
    else if (flag_fwd == 2)
    {      
      //state
      current_time = millis();
      if (left >= 1 && center >= 2 && right >= 1) 
      {
        flag_fwd = 3;
        state = 00;//stop
        cases(state);      
      }


      else if( state == 11)
      {   

        if (left >= 1 && center >= 2 && right >= 1) 
        {
          flag_fwd =3; 
          state = 00;//stop
          cases(state);
                      
        }
       else if(left >= 1 && center >= 1 && right == 0)
        {
          flag_fwd =3;
          state = 00 ;
          cases(state);   
        }   
       else if(left == 0 && center >= 1 && right >= 1) 
        {
          flag_fwd=3;
          state = 00;//right
          cases(state);
        }        
        else if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;//fordward
          cases(state);
        }


        else if(left >= 1 && center == 0 && right == 0)
        {
        //  while((state == 11) && (millis()<current_time+5))
          //{
            state = 10;//left  right
            cases(state);
         // }
        }   
        else if(left == 0 && center == 0 && right >= 1)
        {
          //while((state == 11) && (millis()<current_time+5))
        //  {
            state = 01;//left
            cases(state);
          //}
        }

        else 
        {
          state=11;//fordward
          cases(state);
        }
      }   

      else if (state == 01)
      {
        if ((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 1 && right == 0) || (left >= 0 && center >= 1 && right >= 1))
        {
           flag_fwd =3;
          state = 00;//stop
          cases(state);
         
        }
        else  if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if(left >= 1 && center == 0 && right == 0)
        {
          state = 10;//left
          cases(state);
        }  
      }   

      else  if (state == 10)
      {
        if ((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 1 && right == 0) || (left >= 0 && center >= 1 && right >= 1))
        {
          flag_fwd =3;
          state = 00;//stop
          cases(state);            
        }             
        else if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if (left == 0 && center == 0 && right >= 1)
        {
          state = 01;//right
          cases(state);
        }  
      }
    }
  }  
  return state; 
}

/*-------------------- forward line follow function of the end here --------------------------------------*/


 
 
 
 
 
 /*
* Function Name:right_turn
* Input: Initial state 
* Output: None
* Logic: implementation for right turn at node.
* Example call : right_turn( state )
/*
/*###############################################################################################
 #################################################################################################
 ------------------       program for taking right turn           ---------------------*/


int  right_turn(int state )
{
  fwd_go = 11;
  turn_go = 00;
  flag_rgt = 0;
  while (flag_rgt !=3 )
  {
    sensor_data();
      if ( (state == 00)  && flag_rgt ==0 )
      { 
        if ((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 1 && right >= 0) || (left >= 0 && center >= 1 && right >= 1) )
        {
          flag_rgt++;
          turn=00;
          state =01;//left motor
          cases(state);
          
        }
      }
      else if (state ==01 || flag_rgt == 0)
      {
          if (left >= 0 && center >= 1 && right >= 0)
          {
            flag_rgt = 3;
            state =00;//left motor
            cases(state);
          }
          else if  ((left >= 1 && center >= 3 && right >= 1) ||(left >= 1 && center >= 3 && right >= 0) )
          {
            state =01;//right motor
            cases(state);
          }
        
          else if((left >= 0 && center >= 3 && right >= 1) || (left >= 0 && center >= 0 && right >= 1) || (left >= 0 && center >= 0 && right >= 0) || (left >= 1 && center >= 0 && right >= 0)   || (left >= 1 && center >= 3 && right >= 0))
          {
            state = 01;//left motor
            cases(state);
          } 

      }
    }   
  
return state;  
}
/*-------------------- right turn function of the end here --------------------------------------*/





/*###############################################################################################
 #################################################################################################


/*-----------------------     end here                     --------------------------------------*/
 








/*###############################################################################################
 #################################################################################################
 ------------------       program to follow forward line to node turn           ---------------------*/
int line_fwd(int state )
{
  fwd_go = 11;
  flag_fwd = 0;
  while (flag_fwd != 9)
  { 
    sensor_data();
    current_time = millis();
    if (left >= 1 && center >= 2 && right >= 1) 
    {
      flag_fwd = 9;
      state = 00;//stop
      cases(state);      
    }


    else if(fwd_go == 11)
    {   
      if(left == 0 && center >= 1 && right == 0)
      {
        state = 11;//backward
        cases(state);
      }
      else if (left >= 1 && center >= 2 && right >= 1) 
      {
        flag_fwd= 9;
        state = 00;//stop
        cases(state);
      }
      else if(left >= 1 && center >= 1 && right == 0)
      {
        flag_fwd = 9;
        state = 00 ;
        cases(state);   
      }
      else if(left == 0 && center >= 1 && right >= 1) 
      {
        flag_fwd = 9 ;
        state = 00;//left
        cases(state);
      }
      else if(left >= 1 && center == 0 && right == 0)
      {
        //while((state == 11) && (millis()<current_time+5))
        //{
          state = 10;//right
          cases(state);
        //}
      }  

      else if(left == 0 && center == 0 && right >= 3)
      {
       // while((state == 11) && (millis()<current_time+5))
        //{
          state = 01;//right
          cases(state);
       // }
      } 
      else 
      {
        state=11;//backward
        cases(state);
      }
    }   

    else if (state == 01)
    {
      if ((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 1 && right == 0) || (left >= 0 && center >= 1 && right >= 1))
      {
        flag_fwd = 9;
        state = 00;//stop
        cases(state);
      }
      else  if(left == 0 && center >= 1 && right == 0)
      {
        state = 11;
        cases(state);
      }
      else if(left >= 1 && center == 0 && right == 0)
      {
        state = 10;//right
        cases(state);
      }  
    }   

    else  if (state == 10)
    {
      if ((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 1 && right == 0) || (left >= 0 && center >= 1 && right >= 1)) 
      {
        flag_fwd = 9;
        state = 00;//stop
        cases(state);            
      }             
      else if(left == 0 && center >= 2 && right == 0)
      {
        state = 11;
        cases(state);
      }
      else if (left == 0 && center == 0 && right >= 2)
      {
        state = 01;//left
        cases(state);
      }  
    }
  }     
  return state;
}
/*-------------------- line follow function of the end here --------------------------------------*/

 /*
* Function Name:line_bck
* Input: Initial state 
* Output: None
* Logic:implementation for backward traversal.
* Example call : line_bck( state )
/
/*###############################################################################################
 #################################################################################################
 ------------------       program to follow backward line to node turn           ---------------------*/
int line_bck( int state )
{
  fwd_go = 00 ; //backward
  flag_bck =0;
  i=20;
  while (flag_bck != 9)
  {  

    sensor_data(); 

    if (state == 00)
    {
      if ((left >= 0 && center >= 1 && right >= 0) || (left >= 1 && center >= 1 && right >= 0) || (left >= 1 && center >= 0 && right >= 0) || (left >= 0 && center >= 0 && right >= 0) || (left >= 0 && center >= 0 && right >= 1) || (left >= 0 && center >= 1 && right >= 1) || (left >=1  && center >= 1 && right >= 1)  )
      { 

        flag_bck = 1;
        state = 11;
        cases(state); 
         
      }   
    }

    else if (flag_bck == 1)
    {
      if( state == 11)
      {
        if(left == 0 && center >= 1 && right == 0)
        {
          flag_bck =2;
          state = 11;//fordward
          cases(state);
           

        }     
        else if((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1))
        {
          state = 00;//fordward
          cases(state); 
          break;
            
             
        }
        else if( (left >= 3 && center == 0 && right == 0))
        {
          state = 01;//left
          cases(state);

        }
        else if(left >= 1 && center >= 1 && right >= 0) 
        {
          state = 00 ;
          cases(state);
          break;
        }
        else if( (left == 0 && center == 0 && right >= 3)) 
        {
          state = 10;//right
          cases(state);
        } 
       else if(left == 0 && center >= 1 && right >= 1) 
        {
          state = 00 ;
          cases(state);
          break;
        }
      }     

      else if (state == 01)
      {
        if(left == 0 && center >= 1 && right == 0)
        {
          flag_bck =2;  
          state = 11;
          cases(state);

        }     
        else if((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1))
        {
          flag_bck =9;
          state = 00;
          cases(state);
          break;
        }
        else if((left >= 1 && center == 0 && right == 0))
        {

          state = 01;//left
          cases(state); 
        }  
        else if(left >=1 && center >= 1 && right >= 0) 
        {
          state = 00 ;
          cases(state);
          break;
        }
      }      
      else  if (state == 10)
      {
        if(left == 0 && center >= 1 && right == 0)
        {
          flag_bck =2;
          state = 11;
          cases(state); 
        }      
        else if((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1))
        {
          flag_bck = 9;
          state = 00;
          cases(state);  
           break;
        }
        else if( (left == 0 && center == 0 && right >= 2)) 
        {
          state = 10;//right
          cases(state);
        }  
        else if(left == 0 && center >= 1 && right >= 1) 
        {
          state = 00 ;
          cases(state);
          break;
        }
      }
    }





    //follow straight line
    else if(flag_bck == 2)
    {      
      //state
      current_time = millis();
     if( state == 11)
      {   

        if ((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1))
        {
          flag_bck =9; 
          state = 00;//stop
          cases(state);
          break;
  
        }
        else if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;//fordward
          cases(state);
        }


        else if(left >= 1 && center == 0 && right == 0)
        {
//          while((state == 11) && (millis()<current_time+10))
//          {
            state = 01;//left  right
            cases(state);
    //      }
        }  
        else if(left >= 0 && center >= 1 && right >= 1) 
        {
          flag_bck = 9 ;
          state = 00 ;
          cases(state);
       break;  
      
        }
        else if(left == 0 && center == 0 && right >= 1)
        {
//          while((state == 11) && (millis()<current_time+10))
//          {
            state = 10;//left
            cases(state);
        //  }
        }
        else if(left >= 1 && center >= 1 && right >= 0) 
        {
          flag_bck = 9;
          state = 00;//right
          cases(state);
          break;
           
        } 
//        else 
//        {
//          state=11;//fordward
//          cases(state);
//        }
      }   

      else if (state == 01)
      {
        if ((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1))
        {
          flag_bck =9;
          state = 00;//stop
          cases(state);
          break; 

        }
        else  if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if(left >= 1 && center == 0 && right == 0)
        {
          state = 01;//left
          cases(state);
        }  
                else if(left >= 1 && center >= 1 && right >= 0) 
        {
          flag_bck = 9;
          state = 00;//right
          cases(state);
          break;
           
        }
      }   

      else  if (state == 10)
      {
        if ((left >= 1 && center >= 1 && right >= 1) || (left >= 1 && center >= 0 && right >= 1)) 
        {
          flag_bck =9;
          state = 00;//stop
          cases(state);
          break;
         
        }             
        else if(left == 0 && center >= 1 && right == 0)
        {
          state = 11;
          cases(state);
        }
        else if (left == 0 && center == 0 && right >= 2)
        {
          state = 10;//right
          cases(state);
        }  
                else if(left >= 0 && center >= 1 && right >= 1) 
        {
          flag_bck = 9 ;
          state = 00 ;
          cases(state);
       break;  
      
        }
      }
    }
  }  
  //return state;
 
}
/*-------------------- backward line follow function of the end here --------------------------------------*/


 
 
 /*
* Function Name:line_bck
* Input: Initial state 
* Output: None
* Logic: implementation for backward traversal.
* Example call : line_bck( state )
/*

/*###############################################################################################
 #################################################################################################
 ------------------       program to follow backward line to node turn     ---------------------*/
int line_bck1( int state )
{
  fwd_go = 00 ; //backward
  flag_bck = 0;
  while (flag_bck != 9)
  {  
    sensor_data();    
    //state
    current_time = millis();
    if (left >= 1 && center >= 2 && right >= 1) 
    {
      flag_bck =9;
      state = 00;//stop
      cases(state);      
    }


    else if( fwd_go == 00 )
    {   
      if(left == 0 && center >= 1 && right == 0)
      {
        state = 11;//backward
        cases(state);
      }
      else if (left >= 1 && center >= 2 && right >= 1) 
      {
        flag_bck =9;
        state = 00;//stop
        cases(state);
      }

      else if(left >= 1 && center == 0 && right == 0)
      {
 
          state = 10;//right
          cases(state);
        
      }  
      else if(left >= 1 && center >= 1 && right == 0)
      {
       
        state = 10 ;
        cases(state);   
      }
      else if(left == 0 && center == 0 && right >= 3)
      {

          state = 01;//right
          cases(state);
        
      }
      else if(left == 0 && center >= 1 && right >= 1) 
      {
        
        state = 01;//left
        cases(state);
      } 
      else 
      {
        state=11;//backward
        cases(state);
      }
    }   

    else if (state == 01)
    {
      if (left >= 1 && center >= 1 && right >= 1) 
      {
        flag_bck =9;
        state = 00;//stop
        cases(state);
      }
      else  if(left == 0 && center >= 1 && right == 0)
      {
        state = 11;
        cases(state);
      }
      else if( (left >= 1 && center == 0 && right == 0) || (left >= 1 && center >= 1 && right == 0)  )
      {
        state = 10;//right
        cases(state);
      }  
    }   

    else  if (state == 10)
    {
      if (left >= 1 && center >= 1 && right >= 1) 
      {
        flag_bck = 9;
        state = 00;//stop
        cases(state);            
      }             
      else if(left == 0 && center >= 2 && right == 0)
      {
        state = 11;
        cases(state);
      }
      else if( (left == 0 && center == 0 && right >= 2) || (left == 0 && center >= 1 && right >= 1) )
      {
        state = 01;//left
        cases(state);
      }  
    }
  }

  return state; 
}
/*-------------------- backward line follow function of the end here --------------------------------------*/


 
 
 /*
* Function Name:left_turn
* Input: Initial state 
* Output: None
* Logic: implementation for left turn at node.
* Example call : left_turn( state )
/*
/*###############################################################################################
 #################################################################################################
 ------------------       program for taking left turn           ---------------------*/

int  left_turn(int state)
{ 
  fwd_go = 11;
  turn_go = 11;
  flag_lft = 0;
  while(flag_lft != 9)
  { 
    sensor_data();
    
//    i=10;
//    
//    if(flag_fwd == 3 || flag_fwd == 9 )
//    { 
//      if( left == 0 && center >= 1 && right >= 1) 
//      { current_time=millis();
//        while((millis()<current_time+15))
//        {
//          //sensor_data();
//          state = 10;//
//          cases(state);
////          if ( left == 0 && center >= 1 && right >= 0)
////          {
////            flag_bck = 0;//any arbitary flag to call backward line to node 
////            flag_fwd = 5;//any arbitary flag
////            //break;
////          }  
//        }
//      } 
//      if(left == 1 && center >= 1 && right == 0) 
//      {
//        current_time=millis();
//        while((millis()<current_time+15))
//        {
//          //sensor_data();
//          state = 10;//
//          cases(state);
////          if ( left == 0 && center >= 1 && right >= 0)
////          {
////            flag_bck = 0;//any arbitary flag to call backward line to node 
////            flag_fwd = 5;//any arbitary flag
////           // break;
////          }
//        }  
//      } 
//    }     

    if ((state == 00)  && flag_lft == 0 )
    { 
    
     if ((left >= 1 && center >= 2 && right >= 1) || (left >= 1 && center >= 2 && right >= 0) || (left >= 0 && center >= 2 && right >= 1))
      {
        flag_lft=5;
        turn=11;
        state =10;//right turn
        cases(state);
        
      }
    } 
    else if(state ==10   && flag_lft == 5 )
    {
      if(left == 0 && center >= 1 && right == 0)
      {
        flag_lft=9;
        state = 00;//stop
        cases(state); 
      }    

      else if ((left >= 1 && center >= 3 && right >= 1 )||(left >= 0 && center >= 3 && right >= 1 ))
      {
        state =10;//right motor
        cases(state);
      }

      else if((left >= 1 && center >= 3 && right >= 0) || (left >= 1 && center >= 0 && right >= 0) || (left >= 0 && center >= 0 && right >= 0) || (left >= 0 && center >= 0 && right >= 1) || (left >= 0 && center >= 3 && right >= 1))
      {
        state = 10;//right motor
        cases(state);
      } 

    }
  }
  return state;
} 
/*-------------------- left turn function of the end here --------------------------------------*/


 
 
 
 
