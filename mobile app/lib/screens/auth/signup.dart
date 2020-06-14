import 'package:flutter/material.dart';
import 'package:smart_kitchen_inventory/screens/welcomeScreen/WelcomeScreen.dart';
String _name, _email, _password;

class SignUp extends StatefulWidget {
  @override
  _SignUpState createState() => _SignUpState();
}

class _SignUpState extends State<SignUp> {
  TextEditingController _emailController = TextEditingController();
  TextEditingController _nameController = TextEditingController();
  TextEditingController _passwordController = TextEditingController();

  

  @override
  Widget build(BuildContext context) {
    return Scaffold(
    appBar: AppBar(
      
        leading: Icon(Icons.satellite,size: 30,color: Colors.blue.shade900,),
        title:Text('Sign in ',style: TextStyle(
          color: Colors.black,
          fontSize: 25,
          fontWeight: FontWeight.bold
        ),
        )
      ),
      body:Padding(
        padding: EdgeInsets.all(10),
        child: ListView(
          children:<Widget>[
            Container(
              alignment:Alignment.center,
              padding: EdgeInsets.all(10),
              child: Text(
                'Smart Tracking App',
                style: TextStyle(
                  color: Colors.blue.shade900,
                  fontWeight: FontWeight.bold,
                  fontSize: 30
                ),
              ),
            ),
            Container(
              alignment: Alignment.center,
              padding: EdgeInsets.all(10),
              child: TextFormField(
                validator: (input){
                  if(input.isEmpty){
                    return 'please type something';
                  }
                },
                onSaved: (input)=>_name = input,
                controller: _nameController,
                decoration: InputDecoration(
                  border: OutlineInputBorder(),
                  labelText: 'Name'
                ),
              ),
            ),
            Container(
              alignment: Alignment.center,
              padding: EdgeInsets.all(10),
              child: TextFormField(
                validator: (input){
                  if(input.isEmpty){
                    return 'please type something';
                  }
                },
                onSaved: (input)=>_email = input,
                controller: _emailController,
                decoration: InputDecoration(
                  border: OutlineInputBorder(),
                  labelText: 'Email'
                ),
              ),
            ),
            Container(
              alignment: Alignment.center,
              padding: EdgeInsets.all(10),
              child: TextFormField(
                validator: (input){
                  if(input.isEmpty){
                    return 'please type something';
                  }
                },
                onSaved: (input)=>_password = input,
                obscureText: true,
                controller: _passwordController,
                decoration: InputDecoration(
                  border: OutlineInputBorder(),
                  labelText: 'Password'
                ),
              ),
            ),
            Container(
              padding: EdgeInsets.all(10),
              child: RaisedButton(
                textColor: Colors.white,
                color: Colors.blue,
                child: Text('Register'),
                shape:RoundedRectangleBorder(borderRadius: BorderRadius.all(Radius.elliptical(16.0,13.0))),
                elevation: 5,
                onPressed: (){
                  print(_nameController.text.toString());
                  print(_emailController.text.toString());
                  // if(_email.contains("@")){
                                      Navigator.push(
                                        context, MaterialPageRoute(builder: (context) => WelcomeScreen(),),
                                      );
                                    // }else SnackBar(content: Text('error huu huu'));
                                  },
                                ),
                              ),
                    

                              
                  
                  
                  
                            ],
                          ),
                        )
                        
                      );
  }
}