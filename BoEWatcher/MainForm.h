#pragma once
#include "Manager.hpp"
#include "Injector.hpp"

Manager* Watcher = new Manager();
char* ProcessPath = NULL;

namespace BoEWatcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	protected:
	private: System::Windows::Forms::ColumnHeader^  columnHeader_Account;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_Char;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_Status;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_Gains;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_Level;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_Area;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_Watcher;
	private: System::Windows::Forms::ToolStripMenuItem^  launchToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  removeKillsProcessToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Button^  button_SelectPoEFolder;
	private: System::Windows::Forms::TextBox^  textBox_ProcessArgs;
	private: System::Windows::Forms::TextBox^  textBox_Character;
	private: System::Windows::Forms::TextBox^  textBox_Password;
	private: System::Windows::Forms::TextBox^  textBox_Username;
	private: System::Windows::Forms::ComboBox^  comboBox_BotType;
	private: System::Windows::Forms::ComboBox^  comboBox_Realm;
	private: System::Windows::Forms::Button^  button_AddAccount;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_Realm;












	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader_Account = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_Char = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_Status = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_Gains = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_Level = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_Area = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_Watcher = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->launchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeKillsProcessToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button_AddAccount = (gcnew System::Windows::Forms::Button());
			this->textBox_Username = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Password = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Character = (gcnew System::Windows::Forms::TextBox());
			this->comboBox_Realm = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_BotType = (gcnew System::Windows::Forms::ComboBox());
			this->textBox_ProcessArgs = (gcnew System::Windows::Forms::TextBox());
			this->button_SelectPoEFolder = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->columnHeader_Realm = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_Watcher->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(7) {
				this->columnHeader_Account,
					this->columnHeader_Char, this->columnHeader_Status, this->columnHeader_Gains, this->columnHeader_Realm, this->columnHeader_Area,
					this->columnHeader_Level
			});
			this->listView1->ContextMenuStrip = this->contextMenuStrip_Watcher;
			this->listView1->Dock = System::Windows::Forms::DockStyle::Right;
			this->listView1->FullRowSelect = true;
			this->listView1->GridLines = true;
			this->listView1->Location = System::Drawing::Point(234, 0);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(456, 263);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader_Account
			// 
			this->columnHeader_Account->Text = L"Account";
			this->columnHeader_Account->Width = 86;
			// 
			// columnHeader_Char
			// 
			this->columnHeader_Char->Text = L"Character";
			this->columnHeader_Char->Width = 69;
			// 
			// columnHeader_Status
			// 
			this->columnHeader_Status->Text = L"Status";
			this->columnHeader_Status->Width = 62;
			// 
			// columnHeader_Gains
			// 
			this->columnHeader_Gains->Text = L"Orb Gains";
			this->columnHeader_Gains->Width = 63;
			// 
			// columnHeader_Level
			// 
			this->columnHeader_Level->DisplayIndex = 4;
			this->columnHeader_Level->Text = L"Level";
			this->columnHeader_Level->Width = 45;
			// 
			// columnHeader_Area
			// 
			this->columnHeader_Area->Text = L"Area";
			this->columnHeader_Area->Width = 67;
			// 
			// contextMenuStrip_Watcher
			// 
			this->contextMenuStrip_Watcher->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->launchToolStripMenuItem,
					this->removeKillsProcessToolStripMenuItem
			});
			this->contextMenuStrip_Watcher->Name = L"contextMenuStrip_Watcher";
			this->contextMenuStrip_Watcher->Size = System::Drawing::Size(193, 48);
			this->contextMenuStrip_Watcher->Text = L"Options";
			// 
			// launchToolStripMenuItem
			// 
			this->launchToolStripMenuItem->Name = L"launchToolStripMenuItem";
			this->launchToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->launchToolStripMenuItem->Text = L"Launch";
			// 
			// removeKillsProcessToolStripMenuItem
			// 
			this->removeKillsProcessToolStripMenuItem->Name = L"removeKillsProcessToolStripMenuItem";
			this->removeKillsProcessToolStripMenuItem->Size = System::Drawing::Size(192, 22);
			this->removeKillsProcessToolStripMenuItem->Text = L"Remove (Kills process)";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tabControl1);
			this->groupBox1->Location = System::Drawing::Point(2, -1);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(226, 262);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Controls";
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage1->Controls->Add(this->button_SelectPoEFolder);
			this->tabPage1->Controls->Add(this->textBox_ProcessArgs);
			this->tabPage1->Controls->Add(this->textBox_Character);
			this->tabPage1->Controls->Add(this->textBox_Password);
			this->tabPage1->Controls->Add(this->textBox_Username);
			this->tabPage1->Controls->Add(this->comboBox_BotType);
			this->tabPage1->Controls->Add(this->comboBox_Realm);
			this->tabPage1->Controls->Add(this->button_AddAccount);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(207, 216);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Account Mgmt.";
			// 
			// button_AddAccount
			// 
			this->button_AddAccount->Location = System::Drawing::Point(6, 187);
			this->button_AddAccount->Name = L"button_AddAccount";
			this->button_AddAccount->Size = System::Drawing::Size(89, 23);
			this->button_AddAccount->TabIndex = 0;
			this->button_AddAccount->Text = L"Add + Launch PoE";
			this->button_AddAccount->UseVisualStyleBackColor = true;
			this->button_AddAccount->Click += gcnew System::EventHandler(this, &MainForm::button_AddAccount_Click);
			// 
			// textBox_Username
			// 
			this->textBox_Username->Location = System::Drawing::Point(6, 8);
			this->textBox_Username->Name = L"textBox_Username";
			this->textBox_Username->Size = System::Drawing::Size(149, 20);
			this->textBox_Username->TabIndex = 1;
			this->textBox_Username->Text = L"Username/Email";
			// 
			// textBox_Password
			// 
			this->textBox_Password->Location = System::Drawing::Point(6, 36);
			this->textBox_Password->Name = L"textBox_Password";
			this->textBox_Password->PasswordChar = '*';
			this->textBox_Password->Size = System::Drawing::Size(149, 20);
			this->textBox_Password->TabIndex = 2;
			this->textBox_Password->Text = L"Password";
			// 
			// textBox_Character
			// 
			this->textBox_Character->Location = System::Drawing::Point(6, 95);
			this->textBox_Character->Name = L"textBox_Character";
			this->textBox_Character->Size = System::Drawing::Size(149, 20);
			this->textBox_Character->TabIndex = 3;
			this->textBox_Character->Text = L"Character Name";
			// 
			// comboBox_Realm
			// 
			this->comboBox_Realm->FormattingEnabled = true;
			this->comboBox_Realm->Items->AddRange(gcnew cli::array< System::Object^  >(13) {
				L"Washington, D.C. (US)", L"Texas (US)", L"California (US)",
					L"Amsterdam (EU)", L"London (EU)", L"Frankfurt (EU)", L"Milan (EU)", L"Singapore", L"Australia", L"Sao Paulo (BR)", L"Paris (EU)",
					L"Moscow (RU)", L"Japan"
			});
			this->comboBox_Realm->Location = System::Drawing::Point(6, 64);
			this->comboBox_Realm->Name = L"comboBox_Realm";
			this->comboBox_Realm->Size = System::Drawing::Size(149, 21);
			this->comboBox_Realm->TabIndex = 4;
			this->comboBox_Realm->Text = L"Washington, D.C. (US)";
			// 
			// comboBox_BotType
			// 
			this->comboBox_BotType->FormattingEnabled = true;
			this->comboBox_BotType->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Delve", L"Delve (No Encounter)", L"Generic",
					L"Atlas", L"Niko Farm"
			});
			this->comboBox_BotType->Location = System::Drawing::Point(6, 125);
			this->comboBox_BotType->Name = L"comboBox_BotType";
			this->comboBox_BotType->Size = System::Drawing::Size(149, 21);
			this->comboBox_BotType->TabIndex = 5;
			this->comboBox_BotType->Text = L"Bot Type";
			// 
			// textBox_ProcessArgs
			// 
			this->textBox_ProcessArgs->Location = System::Drawing::Point(6, 156);
			this->textBox_ProcessArgs->Name = L"textBox_ProcessArgs";
			this->textBox_ProcessArgs->Size = System::Drawing::Size(149, 20);
			this->textBox_ProcessArgs->TabIndex = 6;
			this->textBox_ProcessArgs->Text = L"\"C:\\Program Files (x86)\\Grinding Gear Games\\PoE\\PathOfExile_x64.exe\" ";
			// 
			// button_SelectPoEFolder
			// 
			this->button_SelectPoEFolder->Location = System::Drawing::Point(101, 187);
			this->button_SelectPoEFolder->Name = L"button_SelectPoEFolder";
			this->button_SelectPoEFolder->Size = System::Drawing::Size(102, 23);
			this->button_SelectPoEFolder->TabIndex = 7;
			this->button_SelectPoEFolder->Text = L"Select PoE Folder";
			this->button_SelectPoEFolder->UseVisualStyleBackColor = true;
			this->button_SelectPoEFolder->Click += gcnew System::EventHandler(this, &MainForm::button_SelectPoEFolder_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Location = System::Drawing::Point(6, 15);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(215, 242);
			this->tabControl1->TabIndex = 0;
			// 
			// columnHeader_Realm
			// 
			this->columnHeader_Realm->DisplayIndex = 6;
			this->columnHeader_Realm->Text = L"Realm";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(690, 263);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->listView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"BoE Watcher";
			this->contextMenuStrip_Watcher->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		
	private: System::Void button_SelectPoEFolder_Click(System::Object^  sender, System::EventArgs^  e) 
	{

		OpenFileDialog^ ProfileDialog = gcnew OpenFileDialog;
		ProfileDialog->InitialDirectory = "C:\\";
		ProfileDialog->Filter = "exe files (*.exe)|*.exe|All files (*.*)|*.*";
		ProfileDialog->FilterIndex = 2;
		ProfileDialog->ShowHelp = true;
		ProfileDialog->RestoreDirectory = true;

		if (ProfileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (System::IO::File::Exists(ProfileDialog->FileName))
			{
				MessageBox::Show(ProfileDialog->FileName);
				ProcessPath = (char*)(void*)Marshal::StringToHGlobalAnsi(ProfileDialog->FileName);
			}
		}

	}
private: System::Void button_AddAccount_Click(System::Object^  sender, System::EventArgs^  e) 
{

	if (ProcessPath == NULL)
	{
		MessageBox::Show("Please select PoE Process before adding accounts.");
		return;
	}

	if (this->textBox_ProcessArgs->Text == String::Empty)
	{
		MessageBox::Show("Please enter launch arguments before adding accounts.");
		return;
	}
	
	this->textBox_ProcessArgs->Text = this->textBox_ProcessArgs->Text + "--account=" + this->textBox_Username->Text + " --pw=" + this->textBox_Password->Text
		+ " --character=" + this->textBox_Character->Text + " --realm=Washington" + " --bottype=generic";

	char* LaunchArgs = (char*)(void*)Marshal::StringToHGlobalAnsi(this->textBox_ProcessArgs->Text);

	Launcher* L = new Launcher();
	L->SetLaunchArguments(LaunchArgs);
	
	if (!L->LaunchProcess())
	{
		MessageBox::Show("Failed to launch process.");
		return;
	}

	//Add account to listview
	L->GetAccount()->SetAccountName(std::string((char*)(void*)Marshal::StringToHGlobalAnsi(this->textBox_Username->Text)));
	L->GetAccount()->SetPassword(std::string((char*)(void*)Marshal::StringToHGlobalAnsi(this->textBox_Password->Text)));
	L->GetAccount()->SetCharacterName(std::string((char*)(void*)Marshal::StringToHGlobalAnsi(this->textBox_Character->Text)));

	array<String^>^ subItems = gcnew array<String^>(7);
	subItems[0] = gcnew String(this->textBox_Username->Text);
	subItems[1] = gcnew String(this->textBox_Character->Text);
	subItems[2] = gcnew String("IDLE");
	subItems[3] = gcnew String("N/A");
	subItems[4] = gcnew String(this->comboBox_Realm->Text);
	subItems[5] = gcnew String("N/A");
	subItems[6] = gcnew String("N/A");
	ListViewItem^ itm = gcnew ListViewItem(subItems);
	this->listView1->Items->Add(itm);

	Watcher->AddAccount(L);

	Injector* I = new Injector();
	I->Inject(L->GetProcess()->GetProcessID(), "BoE.dll");

	Sleep(3000);
	L->GetProcess()->ChangeWindowTitle(std::string((char*)(void*)Marshal::StringToHGlobalAnsi(this->textBox_Username->Text)));

	if (!Watcher->StartMonitor())	
		MessageBox::Show("Error: Somehow launching with no accounts properly added.");
	
	delete LaunchArgs;
}
};
}
