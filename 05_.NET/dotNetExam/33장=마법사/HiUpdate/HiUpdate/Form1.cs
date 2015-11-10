﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace HiUpdate
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void tblPeopleBindingNavigatorSaveItem_Click(object sender, EventArgs e)
		{
			this.Validate();
			this.tblPeopleBindingSource.EndEdit();
			this.tableAdapterManager.UpdateAll(this.aDOTestDataSet);

		}

		private void Form1_Load(object sender, EventArgs e)
		{
			// TODO: 이 코드는 데이터를 'aDOTestDataSet.tblSale' 테이블에 로드합니다. 필요한 경우 이 코드를 이동하거나 제거할 수 있습니다.
			this.tblSaleTableAdapter.Fill(this.aDOTestDataSet.tblSale);
			// TODO: 이 코드는 데이터를 'aDOTestDataSet.tblPeople' 테이블에 로드합니다. 필요한 경우 이 코드를 이동하거나 제거할 수 있습니다.
			this.tblPeopleTableAdapter.Fill(this.aDOTestDataSet.tblPeople);

		}

		private void btnUpdate_Click(object sender, EventArgs e)
		{
			/* 정상적인 순서
			tblPeopleTableAdapter.Update(aDOTestDataSet.tblPeople);
			tblSaleTableAdapter.Update(aDOTestDataSet.tblSale);
			//*/

			/* 반대 순서
			tblSaleTableAdapter.Update(aDOTestDataSet.tblSale);
			tblPeopleTableAdapter.Update(aDOTestDataSet.tblPeople);
			//*/

			//* 매니저의 Update 메소드 호출
			this.tableAdapterManager.UpdateAll(this.aDOTestDataSet);
			//*/
		}
	}
}
