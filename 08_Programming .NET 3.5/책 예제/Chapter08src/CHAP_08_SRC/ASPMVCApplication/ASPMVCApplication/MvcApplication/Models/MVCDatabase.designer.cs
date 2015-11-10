﻿#pragma warning disable 1591
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:2.0.50727.1433
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace MvcApplication.Models
{
	using System.Data.Linq;
	using System.Data.Linq.Mapping;
	using System.Data;
	using System.Collections.Generic;
	using System.Reflection;
	using System.Linq;
	using System.Linq.Expressions;
	using System.ComponentModel;
	using System;
	
	
	[System.Data.Linq.Mapping.DatabaseAttribute(Name="MVCDatabase")]
	public partial class MVCDatabaseDataContext : System.Data.Linq.DataContext
	{
		
		private static System.Data.Linq.Mapping.MappingSource mappingSource = new AttributeMappingSource();
		
    #region Extensibility Method Definitions
    partial void OnCreated();
    partial void InsertPerson(Person instance);
    partial void UpdatePerson(Person instance);
    partial void DeletePerson(Person instance);
    partial void InsertShippingMethod(ShippingMethod instance);
    partial void UpdateShippingMethod(ShippingMethod instance);
    partial void DeleteShippingMethod(ShippingMethod instance);
    #endregion
		
		public MVCDatabaseDataContext() : 
				base(global::System.Configuration.ConfigurationManager.ConnectionStrings["MVCDatabaseConnectionString"].ConnectionString, mappingSource)
		{
			OnCreated();
		}
		
		public MVCDatabaseDataContext(string connection) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public MVCDatabaseDataContext(System.Data.IDbConnection connection) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public MVCDatabaseDataContext(string connection, System.Data.Linq.Mapping.MappingSource mappingSource) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public MVCDatabaseDataContext(System.Data.IDbConnection connection, System.Data.Linq.Mapping.MappingSource mappingSource) : 
				base(connection, mappingSource)
		{
			OnCreated();
		}
		
		public System.Data.Linq.Table<Person> Persons
		{
			get
			{
				return this.GetTable<Person>();
			}
		}
		
		public System.Data.Linq.Table<ShippingMethod> ShippingMethods
		{
			get
			{
				return this.GetTable<ShippingMethod>();
			}
		}
	}
	
	[Table(Name="dbo.Person")]
	public partial class Person : INotifyPropertyChanging, INotifyPropertyChanged
	{
		
		private static PropertyChangingEventArgs emptyChangingEventArgs = new PropertyChangingEventArgs(String.Empty);
		
		private int _IDPerson;
		
		private int _IDShippingMethod;
		
		private string _PersonName;
		
		private EntityRef<ShippingMethod> _ShippingMethod;
		
    #region Extensibility Method Definitions
    partial void OnLoaded();
    partial void OnValidate(System.Data.Linq.ChangeAction action);
    partial void OnCreated();
    partial void OnIDPersonChanging(int value);
    partial void OnIDPersonChanged();
    partial void OnIDShippingMethodChanging(int value);
    partial void OnIDShippingMethodChanged();
    partial void OnPersonNameChanging(string value);
    partial void OnPersonNameChanged();
    #endregion
		
		public Person()
		{
			this._ShippingMethod = default(EntityRef<ShippingMethod>);
			OnCreated();
		}
		
		[Column(Storage="_IDPerson", AutoSync=AutoSync.OnInsert, DbType="Int NOT NULL IDENTITY", IsPrimaryKey=true, IsDbGenerated=true)]
		public int IDPerson
		{
			get
			{
				return this._IDPerson;
			}
			set
			{
				if ((this._IDPerson != value))
				{
					this.OnIDPersonChanging(value);
					this.SendPropertyChanging();
					this._IDPerson = value;
					this.SendPropertyChanged("IDPerson");
					this.OnIDPersonChanged();
				}
			}
		}
		
		[Column(Storage="_IDShippingMethod", DbType="Int NOT NULL")]
		public int IDShippingMethod
		{
			get
			{
				return this._IDShippingMethod;
			}
			set
			{
				if ((this._IDShippingMethod != value))
				{
					if (this._ShippingMethod.HasLoadedOrAssignedValue)
					{
						throw new System.Data.Linq.ForeignKeyReferenceAlreadyHasValueException();
					}
					this.OnIDShippingMethodChanging(value);
					this.SendPropertyChanging();
					this._IDShippingMethod = value;
					this.SendPropertyChanged("IDShippingMethod");
					this.OnIDShippingMethodChanged();
				}
			}
		}
		
		[Column(Storage="_PersonName", DbType="VarChar(50)")]
		public string PersonName
		{
			get
			{
				return this._PersonName;
			}
			set
			{
				if ((this._PersonName != value))
				{
					this.OnPersonNameChanging(value);
					this.SendPropertyChanging();
					this._PersonName = value;
					this.SendPropertyChanged("PersonName");
					this.OnPersonNameChanged();
				}
			}
		}
		
		[Association(Name="ShippingMethod_Person", Storage="_ShippingMethod", ThisKey="IDShippingMethod", IsForeignKey=true)]
		public ShippingMethod ShippingMethod
		{
			get
			{
				return this._ShippingMethod.Entity;
			}
			set
			{
				ShippingMethod previousValue = this._ShippingMethod.Entity;
				if (((previousValue != value) 
							|| (this._ShippingMethod.HasLoadedOrAssignedValue == false)))
				{
					this.SendPropertyChanging();
					if ((previousValue != null))
					{
						this._ShippingMethod.Entity = null;
						previousValue.Persons.Remove(this);
					}
					this._ShippingMethod.Entity = value;
					if ((value != null))
					{
						value.Persons.Add(this);
						this._IDShippingMethod = value.IDShippingMethod;
					}
					else
					{
						this._IDShippingMethod = default(int);
					}
					this.SendPropertyChanged("ShippingMethod");
				}
			}
		}
		
		public event PropertyChangingEventHandler PropertyChanging;
		
		public event PropertyChangedEventHandler PropertyChanged;
		
		protected virtual void SendPropertyChanging()
		{
			if ((this.PropertyChanging != null))
			{
				this.PropertyChanging(this, emptyChangingEventArgs);
			}
		}
		
		protected virtual void SendPropertyChanged(String propertyName)
		{
			if ((this.PropertyChanged != null))
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
	}
	
	[Table(Name="dbo.ShippingMethod")]
	public partial class ShippingMethod : INotifyPropertyChanging, INotifyPropertyChanged
	{
		
		private static PropertyChangingEventArgs emptyChangingEventArgs = new PropertyChangingEventArgs(String.Empty);
		
		private int _IDShippingMethod;
		
		private string _ShippingMethod1;
		
		private EntitySet<Person> _Persons;
		
    #region Extensibility Method Definitions
    partial void OnLoaded();
    partial void OnValidate(System.Data.Linq.ChangeAction action);
    partial void OnCreated();
    partial void OnIDShippingMethodChanging(int value);
    partial void OnIDShippingMethodChanged();
    partial void OnShippingMethod1Changing(string value);
    partial void OnShippingMethod1Changed();
    #endregion
		
		public ShippingMethod()
		{
			this._Persons = new EntitySet<Person>(new Action<Person>(this.attach_Persons), new Action<Person>(this.detach_Persons));
			OnCreated();
		}
		
		[Column(Storage="_IDShippingMethod", AutoSync=AutoSync.OnInsert, DbType="Int NOT NULL IDENTITY", IsPrimaryKey=true, IsDbGenerated=true)]
		public int IDShippingMethod
		{
			get
			{
				return this._IDShippingMethod;
			}
			set
			{
				if ((this._IDShippingMethod != value))
				{
					this.OnIDShippingMethodChanging(value);
					this.SendPropertyChanging();
					this._IDShippingMethod = value;
					this.SendPropertyChanged("IDShippingMethod");
					this.OnIDShippingMethodChanged();
				}
			}
		}
		
		[Column(Name="ShippingMethod", Storage="_ShippingMethod1", DbType="VarChar(50) NOT NULL", CanBeNull=false)]
		public string ShippingMethod1
		{
			get
			{
				return this._ShippingMethod1;
			}
			set
			{
				if ((this._ShippingMethod1 != value))
				{
					this.OnShippingMethod1Changing(value);
					this.SendPropertyChanging();
					this._ShippingMethod1 = value;
					this.SendPropertyChanged("ShippingMethod1");
					this.OnShippingMethod1Changed();
				}
			}
		}
		
		[Association(Name="ShippingMethod_Person", Storage="_Persons", OtherKey="IDShippingMethod")]
		public EntitySet<Person> Persons
		{
			get
			{
				return this._Persons;
			}
			set
			{
				this._Persons.Assign(value);
			}
		}
		
		public event PropertyChangingEventHandler PropertyChanging;
		
		public event PropertyChangedEventHandler PropertyChanged;
		
		protected virtual void SendPropertyChanging()
		{
			if ((this.PropertyChanging != null))
			{
				this.PropertyChanging(this, emptyChangingEventArgs);
			}
		}
		
		protected virtual void SendPropertyChanged(String propertyName)
		{
			if ((this.PropertyChanged != null))
			{
				this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
			}
		}
		
		private void attach_Persons(Person entity)
		{
			this.SendPropertyChanging();
			entity.ShippingMethod = this;
		}
		
		private void detach_Persons(Person entity)
		{
			this.SendPropertyChanging();
			entity.ShippingMethod = null;
		}
	}
}
#pragma warning restore 1591
