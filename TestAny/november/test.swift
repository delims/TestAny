//
//  test.swift
//  TestAny
//
//  Created by delims on 2020/11/3.
//  Copyright © 2020 delims. All rights reserved.
//

import Foundation

class November: NSObject {
    
    func hello(msg message:String){
        
        var dict:[String:Any]
        dict = ["1":1,"2":2]
        
        print(dict)
        
    }
  
    func hello2(){
        
        hello(msg: "I am loser")
        
    }
    
    override init() {
        super.init()
        
    }
}
