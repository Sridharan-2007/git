from sqlalchemy.orm import declarative_base 
Base = declarative_base()
from sqlalchemy import Column, Integer, String, Float
Base = declarative_base()

class Products(Base):
    __tablename__ = "products"

    id = Column(Integer, primary_key=True, index=True)
    name = Column(String, index=True)
    price = Column(Float)
    tax = Column(Float, default=None)
