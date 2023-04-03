
%debug
%skeleton "lalr1.cc"
%defines
%define parse.assert
%define api.value.type variant
%define api.token.constructor

%locations

%code requires // *.hh
{


#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string.h>
#include <chrono>

using namespace std;
using namespace std::chrono;


typedef std::list<std::string> strings_type;

class State {
 public:
   int index;
   long long hash_state;
   int arity;
   int level;
   int output = 0;  
   State(int i,int o,int l) {index = i; output =o; level = l;} 

};

class Label{
 public:
   string c;
   int arity;
   Label(string x,int i) {c= x; arity = i;} 
   void setLabel(string s,int a){c = s;arity = a;}
   Label* clone() const { return new Label(*this); }

};

class Automaton {

int index;
public: int level;
        int states;

public:
map<pair<string,int>,list<long long>> TransitionsList;

map<pair<string,int>,map<long long,State*>> TransitionsState;

map<State,vector<list<State*>>> ListStates;

map<pair<string,int>,set<State*>> Q_f;
map<int,map<pair<string,int>,set<State*>>> Q_level;

Automaton* clone() const { return new Automaton(*this); }

};
}

%code // *.cc
{


int STkernel_Hadamard_Product(Automaton*, Automaton*,map<int,set<pair<string,int>>>&);
long long compute_hash(std::string const&);
hash<string> str_hash;

FILE *yyin,*yyout;

Automaton *STautomaton0 = new Automaton();
Automaton *STautomaton1 = new Automaton();
std::vector<Automaton*> ST; 

pair<string,int> symbol;
map<int,set<pair<string,int>>> SYM;




int i=0,j=0,l,x = 0;
long long hash_v;
string hash_w;


  // Prototype of the yylex function providing subsequent tokens.
  static yy::parser::symbol_type yylex();

  namespace std
  {
    std::ostream&
    operator<<(std::ostream& o, const strings_type& s)
    {
      std::copy(s.begin(), s.end(),
                 std::ostream_iterator<strings_type::value_type>(o, "\n"));
      return o;
    }
  }

  // Conversion to string.
  template<typename T>
    inline
    std::string
    string_cast(const T& t)
  {
    std::ostringstream o;
    o << t;
    return o.str();
  }
}
%define api.token.prefix {TOK_}

%token <::std::string>
  SYMBOL
  PO  
  PF  
  VIR 
  RTL 
  ;


%token END  0;

%nterm  <State*> Tx;
%nterm  <list<State*>> Te;
%nterm line;
%nterm file;


%%
file :       {  }
     | line file {}
     ;
line : RTL      { 
               }
     | Tx RTL {   STautomaton0->states = i; 
                 // cout << "automate  with height " << ++STautomaton0->level << endl;
                                i = 0; l = 0;
                
                Automaton* A = STautomaton0->clone(); 
                ST.push_back(A);  free(STautomaton0);
                Automaton* STautomaton0 = new Automaton(); STautomaton0->level = 0;
            }
     ;


Tx : SYMBOL PO  Te  PF  {     
                                  symbol = make_pair($1,$3.size()); 
                                  l =0;
                                    hash_w = "0";
                                    for(auto s : $3){
                                        hash_w += to_string(s->hash_state);
                                        if(l<s->level) l = s->level;
                                    }
                                    hash_v = str_hash(hash_w);                                     
                                      if (STautomaton0->TransitionsState[symbol][hash_v]){
                                                  STautomaton0->TransitionsState[symbol][hash_v]->output++;  
                                                 	$$ = STautomaton0->TransitionsState[symbol][hash_v];
                                             }
                                      else
                                       {  
                                        SYM[l+1].insert(symbol); 
                                        
                                         
                                          $$ = new State(i,1,l+1); 
                                          $$->arity = $3.size(); 
                                          $$->hash_state = str_hash($1+hash_w);
                                         //  cout << " state " << i << " symbol " << symbol.first << "," << symbol.second << ",    "<<l+1 << " : "<<$3.size() << " : " <<hash_v << endl;
                                
                                         i++;
                                         $$->level = l+1;
                                       
                                                  
                                         STautomaton0->TransitionsState[symbol][hash_v]= $$; 
                                         STautomaton0->Q_level[l+1][symbol].insert($$); 

                                         
                                       } 
                                     
                                      if(STautomaton0->level < $$->level)
                                                        STautomaton0->level = $$->level;
                                     
                                    }  
    |SYMBOL               {              
                                                 symbol = make_pair($1,0); 
                                                 hash_v = str_hash($1);
                                              
                                            if (STautomaton0->TransitionsState[symbol][hash_v]){
                                                 STautomaton0->TransitionsState[symbol][hash_v]->output++;

                                                   $$ = STautomaton0->TransitionsState[symbol][hash_v];
                                             }
                                           else
                                              {  
                                                  $$ = new State(i,1,0);  
                                                  SYM[0].insert(symbol); 
                                                
                                                   
                                                     $$->hash_state = hash_v;
                                                   $$->level = 0;
                                                  STautomaton0->TransitionsState[symbol][hash_v] = $$;
                                                  STautomaton0->Q_f[symbol].insert($$); 
                                                  STautomaton0->Q_level[0][symbol].insert($$); 
                                                //  cout << " state " << i << " symbol " << symbol.first << "," << symbol.second << ",   0"<< " : "<< hash_v << endl;
                                             $$->arity = 1;  
                                               i++;
                                                  
                                             } 
                                                                          
                                    }                                     
    ;
Te :  Tx                        { $$.push_back($1); 
                                    
                                }
   | Te   VIR Tx                { for(auto s : $1){
                                        $$.push_back(s);
                                      }
                                  $$.push_back($3);                                     
   ;                           }

%%



static yy::parser::symbol_type yylex()
{      
  char c=fgetc(yyin); 
  //cout << c << endl;
 yy::parser::location_type loc(0, c + 1, c + 1);
   switch (c)
   {
     case '0': return yy::parser::make_SYMBOL(string_cast(c) , loc);
     case '1': return yy::parser::make_SYMBOL(string_cast(c) , loc);
     case '2': return yy::parser::make_SYMBOL(string_cast(c) , loc);
     case '3': return yy::parser::make_SYMBOL(string_cast(c) , loc);
     case '4': return yy::parser::make_SYMBOL(string_cast(c) , loc);
     case '5': return yy::parser::make_SYMBOL(string_cast(c) , loc);
     case '6': return yy::parser::make_SYMBOL(string_cast(c) , loc);
     case '7': return yy::parser::make_SYMBOL(string_cast(c) , loc);
     case '8': return yy::parser::make_SYMBOL(string_cast(c) , loc);
     case '9': return yy::parser::make_SYMBOL(string_cast(c) , loc);
     case ',' : return yy::parser::make_VIR(string_cast(c) , loc);
     case ')' : return yy::parser::make_PF(string_cast(c) , loc);
     case '(' : return yy::parser::make_PO(string_cast(c) , loc);
     case '\n' : return yy::parser::make_RTL(string_cast(c) , loc);
  default: return yy::parser::make_END(loc);
   } 
  
}

// Mandatory error function
void
yy::parser::error(const yy::parser::location_type& loc, const std::string& msg)
{
  std::cerr << loc << ": " << msg << std::endl;
}

/********************************************************************************************/
int STkernel_Hadamard_Product(Automaton* A1, Automaton* A2,map<int ,set<pair<string,int>>> &sym){

int kernel = 0,  alphabet_size = 0;

   for(int i = 0; i<=min(A1->level,A2->level); i++)
     for(auto symbol : sym[i]){
          
     //  cout << "level " << i << "--> ("<< symbol.first << ","<< symbol.second << ")" << endl;
       alphabet_size++;
        if((!A1->Q_level[i][symbol].empty()) && (!A2->Q_level[i][symbol].empty()))
          for(auto s1 : A1->Q_level[i][symbol])    {  
             //  cout << s1->index << " : " << s1->output << " : " <<s1->hash_state << "    "; 
            for(auto s2: A2->Q_level[i][symbol]){
              //  cout << s2->index <<  " : " << s2->output << " : " << s2->hash_state;
                   if(s1->hash_state == s2->hash_state)
                {
                  //  cout << " EQUAL " << endl;
                     kernel += s1->output*s2->output;
                  
                }
              //  else cout << " DIFF " << endl;
            }
          }
     }
//  cout << "Alphabet size : " <<alphabet_size << endl;
return kernel;
}



/****************************************************************************************/
int main(int argc, char* argv[])
{  
 

  map<pair<State*,State*>,int> Cartesian_product;

   int nbStates = 0, treelevel=0;
   long k=1, l=1,KER;
   long kernel= 0,D=0, alpha_size = 0;
    int data_set_size = atoi(argv[3]);

        yy::parser p;
        yyin = fopen(argv[1],"r");
    auto start = chrono::high_resolution_clock::now();  

        p.parse();

    auto stop = chrono::high_resolution_clock::now(); 
    auto structure_construction = chrono::duration_cast<std::chrono::microseconds>(stop - start); 


     for(k=0;k<data_set_size-1;k++){
             for(l=k+1;l<data_set_size;l++){ 

    auto start1 = chrono::high_resolution_clock::now();  
                   
          KER = STkernel_Hadamard_Product(ST[k],ST[l],SYM);
          kernel += KER;
          
    auto stop1 = chrono::high_resolution_clock::now(); 
    auto duration = chrono::duration_cast<std::chrono::microseconds>(stop1 - start1); 

                      D += duration.count();  
    }
  nbStates  += ST[k]->states;
          treelevel += ST[k]->level;
          alpha_size += SYM.size();  
          
           
   }  


    ofstream results;
    results.open (argv[2],ios_base::app);
 
   
   results <<alpha_size/data_set_size << ":" << nbStates/data_set_size << ":" << treelevel/data_set_size << ": kernel : " << kernel/(data_set_size*(data_set_size-1)/2) << " : " << structure_construction.count()/data_set_size <<": temps : " <<D/(data_set_size*(data_set_size-1)/2)<< endl;
   
   results.close();

    
  return 0;
}

// Local Variables:
// mode: C++
// End: