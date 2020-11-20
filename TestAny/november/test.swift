//
//  test.swift
//  TestAny
//
//  Created by delims on 2020/11/3.
//  Copyright © 2020 delims. All rights reserved.
//

import Foundation

prefix operator ++-
postfix operator +++

@objcMembers
class November: NSObject {
    
    static func + (arg2:November, arg:String) {
        print("\(arg)")
    }
    
    static postfix func +++ (arg2:November){
        print("看我多厉害 ")
    }
    
    static prefix func ++- (arg:November){
        print("厉害吧")
    }
    
    func hello(msg message:String){
        var dict:[String:Any]
        dict = ["1":1,"2":2]
        print(dict)
        
//        self.perform(NSSelectorFromString("hello3"))
        
        self+"123"
        self+++
        ++-self
    }
  
    func hello2(){
        hello(msg: "I am loser")
    }
    
    override init() {
        super.init()
        
    }
    


    

}
