#include<iostream>
#include<vector>
using namespace std;
vector<int> path;//to store a single path from root to a leadf
vector< vector<int> > sequence;//to store all of the unique paths
class Node
{
	vector<Node*> steps;
	int info;
	public:
		Node( int value)
		{
			this->info = value;
		}
		void createSequence(int stepsCovered, int maxSteps, vector<int> uniqueSteps )
		{
   			for ( int i=0; i<uniqueSteps.size(); i++)
   			{
				if( stepsCovered + uniqueSteps[i] <= maxSteps )
				{
					Node *newChild = new Node( uniqueSteps[i] );
					this->steps.push_back( newChild );
					newChild->createSequence( stepsCovered+uniqueSteps[i], maxSteps, uniqueSteps );
				}
			}
			
		}
		void getPath()
		{
			path.push_back(this->info);
			if( this->steps.size() == 0 )
			{
				sequence.push_back( path );
			}
			for( int i=0; i<steps.size(); i++)
			{
				steps[i]->getPath();
			}
			path.pop_back();
		}
		};
int main()
{
	int maxSteps;
	Node *root = NULL;
	vector<int> us;
	int tus;
	cout<<"Enter total Number of Unique Steps : ";
	cin>>tus;
	cout<<"Enter maximum steps : ";
	cin>>maxSteps;
	cout<<"Enter Unique Steps : "<<endl;
	int uniqueStep;
	for( int i=0;i<tus;i++)
	{
		cin>>uniqueStep;
		us.push_back(uniqueStep);
	}
	for(int i=0; i<us.size(); i++)
	{
		root = new Node( us[i] );
		root->createSequence(us[i],maxSteps,us);
		root->getPath();
	}
	cout<<"Sequence you can follow to reach on "<<maxSteps<<endl;
	for( int i=0; i<sequence.size();i++)
	{
		for( int j=0;j<sequence[i].size();j++)
		{
			cout<<sequence[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

