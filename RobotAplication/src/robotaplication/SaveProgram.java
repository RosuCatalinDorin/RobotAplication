
package robotaplication;

import java.util.ArrayList;

/**
 *
 * @author CatalinRosu
 */


////    
public class SaveProgram extends Aplicatie {

ArrayList<String> list = new ArrayList<>();
    
String valList  ;   
   
   
  
    
    public void addList(String valList)
    {
        
        list.add(valList);
        
    }

    
    public void showList()
    {
        for (int i = 0; i < list.size(); i++) {
       
            System.out.print(" "+list.get(i));
            
           
        }
        
        
        
            
        }
    
    }

