// A Bison parser, made by GNU Bison 3.0.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:406

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "optimized_RWTA_STkernel.tab.hh"

// User implementation prologue.

#line 51 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:414
// Unqualified %code blocks.
#line 79 "optimized_RWTA_STkernel.yy" // lalr1.cc:415



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

#line 103 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:415


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 189 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:481

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (const stack_symbol_type& that)
    : super_type (that.state, that.location)
  {
    switch (that.type_get ())
    {
      case 3: // SYMBOL
      case 4: // PO
      case 5: // PF
      case 6: // VIR
      case 7: // RTL
        value.copy< ::std::string > (that.value);
        break;

      case 9: // Tx
        value.copy< State* > (that.value);
        break;

      case 10: // Te
        value.copy< list<State*> > (that.value);
        break;

      default:
        break;
    }

  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    switch (that.type_get ())
    {
      case 3: // SYMBOL
      case 4: // PO
      case 5: // PF
      case 6: // VIR
      case 7: // RTL
        value.move< ::std::string > (that.value);
        break;

      case 9: // Tx
        value.move< State* > (that.value);
        break;

      case 10: // Te
        value.move< list<State*> > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 3: // SYMBOL
      case 4: // PO
      case 5: // PF
      case 6: // VIR
      case 7: // RTL
        value.copy< ::std::string > (that.value);
        break;

      case 9: // Tx
        value.copy< State* > (that.value);
        break;

      case 10: // Te
        value.copy< list<State*> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  void
  parser::yypop_ (unsigned n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 3: // SYMBOL
      case 4: // PO
      case 5: // PF
      case 6: // VIR
      case 7: // RTL
        yylhs.value.build< ::std::string > ();
        break;

      case 9: // Tx
        yylhs.value.build< State* > ();
        break;

      case 10: // Te
        yylhs.value.build< list<State*> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 148 "optimized_RWTA_STkernel.yy" // lalr1.cc:856
    {  }
#line 586 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:856
    break;

  case 3:
#line 149 "optimized_RWTA_STkernel.yy" // lalr1.cc:856
    {}
#line 592 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:856
    break;

  case 4:
#line 151 "optimized_RWTA_STkernel.yy" // lalr1.cc:856
    { 
               }
#line 599 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:856
    break;

  case 5:
#line 153 "optimized_RWTA_STkernel.yy" // lalr1.cc:856
    {   STautomaton0->states = i; 
                 // cout << "automate  with height " << ++STautomaton0->level << endl;
                                i = 0; l = 0;
                
                Automaton* A = STautomaton0->clone(); 
                ST.push_back(A);  free(STautomaton0);
                Automaton* STautomaton0 = new Automaton(); STautomaton0->level = 0;
            }
#line 612 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:856
    break;

  case 6:
#line 164 "optimized_RWTA_STkernel.yy" // lalr1.cc:856
    {     
                                  symbol = make_pair(yystack_[3].value.as< ::std::string > (),yystack_[1].value.as< list<State*> > ().size()); 
                                  l =0;
                                    hash_w = "0";
                                    for(auto s : yystack_[1].value.as< list<State*> > ()){
                                        hash_w += to_string(s->hash_state);
                                        if(l<s->level) l = s->level;
                                    }
                                    hash_v = str_hash(hash_w);                                     
                                      if (STautomaton0->TransitionsState[symbol][hash_v]){
                                                  STautomaton0->TransitionsState[symbol][hash_v]->output++;  
                                                 	yylhs.value.as< State* > () = STautomaton0->TransitionsState[symbol][hash_v];
                                             }
                                      else
                                       {  
                                        SYM[l+1].insert(symbol); 
                                        
                                         
                                          yylhs.value.as< State* > () = new State(i,1,l+1); 
                                          yylhs.value.as< State* > ()->arity = yystack_[1].value.as< list<State*> > ().size(); 
                                          yylhs.value.as< State* > ()->hash_state = str_hash(yystack_[3].value.as< ::std::string > ()+hash_w);
                                         //  cout << " state " << i << " symbol " << symbol.first << "," << symbol.second << ",    "<<l+1 << " : "<<$3.size() << " : " <<hash_v << endl;
                                
                                         i++;
                                         yylhs.value.as< State* > ()->level = l+1;
                                       
                                                  
                                         STautomaton0->TransitionsState[symbol][hash_v]= yylhs.value.as< State* > (); 
                                         STautomaton0->Q_level[l+1][symbol].insert(yylhs.value.as< State* > ()); 

                                         
                                       } 
                                     
                                      if(STautomaton0->level < yylhs.value.as< State* > ()->level)
                                                        STautomaton0->level = yylhs.value.as< State* > ()->level;
                                     
                                    }
#line 654 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:856
    break;

  case 7:
#line 201 "optimized_RWTA_STkernel.yy" // lalr1.cc:856
    {              
                                                 symbol = make_pair(yystack_[0].value.as< ::std::string > (),0); 
                                                 hash_v = str_hash(yystack_[0].value.as< ::std::string > ());
                                              
                                            if (STautomaton0->TransitionsState[symbol][hash_v]){
                                                 STautomaton0->TransitionsState[symbol][hash_v]->output++;

                                                   yylhs.value.as< State* > () = STautomaton0->TransitionsState[symbol][hash_v];
                                             }
                                           else
                                              {  
                                                  yylhs.value.as< State* > () = new State(i,1,0);  
                                                  SYM[0].insert(symbol); 
                                                
                                                   
                                                     yylhs.value.as< State* > ()->hash_state = hash_v;
                                                   yylhs.value.as< State* > ()->level = 0;
                                                  STautomaton0->TransitionsState[symbol][hash_v] = yylhs.value.as< State* > ();
                                                  STautomaton0->Q_f[symbol].insert(yylhs.value.as< State* > ()); 
                                                  STautomaton0->Q_level[0][symbol].insert(yylhs.value.as< State* > ()); 
                                                //  cout << " state " << i << " symbol " << symbol.first << "," << symbol.second << ",   0"<< " : "<< hash_v << endl;
                                             yylhs.value.as< State* > ()->arity = 1;  
                                               i++;
                                                  
                                             } 
                                                                          
                                    }
#line 686 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:856
    break;

  case 8:
#line 229 "optimized_RWTA_STkernel.yy" // lalr1.cc:856
    { yylhs.value.as< list<State*> > ().push_back(yystack_[0].value.as< State* > ()); 
                                    
                                }
#line 694 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:856
    break;

  case 9:
#line 232 "optimized_RWTA_STkernel.yy" // lalr1.cc:856
    { for(auto s : yystack_[2].value.as< list<State*> > ()){
                                        yylhs.value.as< list<State*> > ().push_back(s);
                                      }
                                  yylhs.value.as< list<State*> > ().push_back(yystack_[0].value.as< State* > ());                                     
   ;                           }
#line 704 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:856
    break;


#line 708 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:856
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -7;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      -2,     0,    -7,    -1,    -2,     8,     6,    -7,    -7,    -7,
      -7,    -3,    -7,     6,    -7
  };

  const unsigned char
  parser::yydefact_[] =
  {
       2,     7,     4,     0,     2,     0,     0,     5,     3,     1,
       8,     0,     6,     0,     9
  };

  const signed char
  parser::yypgoto_[] =
  {
      -7,    -6,    -7,    -7,     7
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     3,    11,     4,     5
  };

  const unsigned char
  parser::yytable_[] =
  {
      10,     1,    12,    13,     6,     2,     7,    14,     9,     1,
       0,     8
  };

  const signed char
  parser::yycheck_[] =
  {
       6,     3,     5,     6,     4,     7,     7,    13,     0,     3,
      -1,     4
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     7,     9,    11,    12,     4,     7,    12,     0,
       9,    10,     5,     6,     9
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,     8,    12,    12,    11,    11,     9,     9,    10,    10
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     2,     4,     1,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "END", "error", "$undefined", "SYMBOL", "PO", "PF", "VIR", "RTL",
  "$accept", "Tx", "Te", "line", "file", YY_NULLPTR
  };


  const unsigned char
  parser::yyrline_[] =
  {
       0,   148,   148,   149,   151,   153,   164,   201,   229,   232
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 985 "optimized_RWTA_STkernel.tab.cc" // lalr1.cc:1163
#line 238 "optimized_RWTA_STkernel.yy" // lalr1.cc:1164




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
