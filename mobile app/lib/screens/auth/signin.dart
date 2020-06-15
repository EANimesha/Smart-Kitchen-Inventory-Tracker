
import 'package:flutter/material.dart';
import 'package:smart_kitchen_inventory/screens/auth/signup.dart';
import './../welcomeScreen/WelcomeScreen.dart';

class SignIn extends StatefulWidget {
  @override
  _SignInState createState() => _SignInState();
}
String _email, _password;
class _SignInState extends State<SignIn> {
  final GlobalKey<FormState> _formkey = GlobalKey<FormState>();
  TextEditingController nameController = TextEditingController();
  TextEditingController passwordController = TextEditingController();
   @override
  void dispose() {
    // Clean up the controller when the widget is disposed.
    nameController.dispose();
    passwordController.dispose();
    super.dispose();
  }
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
                onSaved: (input)=>_email = input,
                controller: nameController,
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
                controller: passwordController,
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
                child: Text('Login'),
                shape:RoundedRectangleBorder(borderRadius: BorderRadius.all(Radius.elliptical(16.0,13.0))),
                elevation: 5,
                onPressed: (){
                  print(nameController.text.toString());
                  print(passwordController.text.toString());
                  // if(_email.contains("@")){
                                      Navigator.push(
                                        context, MaterialPageRoute(builder: (context) => WelcomeScreen(),),
                                      );
                                    // }else SnackBar(content: Text('error huu huu'));
                                  },
                                ),
                              ),
                              Container(
                                padding: EdgeInsets.fromLTRB(10, 0, 10, 0),
                                child: Center(
                                  child: FlatButton(
                                    child: Text('fogot password?'),
                                    onPressed: () {
                                      //fogot password
                                    },
                                  ),
                                ),
                              ),
                            Container(
                            alignment:Alignment.center,
                            padding: EdgeInsets.all(10),
                            child: Text(
                              'don\'t have an account?',
                              style: TextStyle(
                                color: Colors.blue.shade900,
                                fontWeight: FontWeight.bold,
                                fontSize: 20
                              ),
                            ),
                          ),
                          Container(
              padding: EdgeInsets.all(10),
              child: RaisedButton(
                textColor: Colors.white,
                color: Colors.blue,
                child: Text('Sign Up'),
                shape:RoundedRectangleBorder(borderRadius: BorderRadius.all(Radius.elliptical(13.0,13.0))),
                elevation: 5,
                onPressed: (){
                 
                  // if(_email.contains("@")){
                                      Navigator.push(
                                        context, MaterialPageRoute(builder: (context) => SignUp(),),
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
                  
                  