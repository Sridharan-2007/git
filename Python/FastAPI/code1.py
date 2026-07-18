from fastapi import FastAPI,Path
from models import Products as ProductModel  
from database import Session, engine
from database_models import Products as ProductDBModel

app = FastAPI()

ProductDBModel.metadata.create_all(bind=engine)

products_db= [
    {"id": 1, "name": "Product 1", "price": 10.0, "tax": 1.0},
    {"id": 2, "name": "Product 2", "price": 20.0, "tax": 2.0},
    {"id": 3, "name": "Product 3", "price": 30.0, "tax": 3.0},
]



@app.get("/Products")
def get_products():
    db = Session()
    return products_db 

@app.get("/Products/{product_id}")
def get_product(product_id: int = Path(..., description="The ID of the product to view")):
    for product in products_db:
        if product["id"] == product_id:
            return product
    return {"Data": "Not found"}

@app.post("/Products")
def create_product(product: ProductModel):
    products_db.append(product.dict())
    return product

@app.put("/Products/{product_id}")
def update_product(product_id: int, updated_product: ProductModel):
    for i in range (len(products_db)):
        if products_db[i]["id"] == product_id:
            products_db[i] = updated_product.dict()
            return updated_product
    return {"Data": "Not found"}

@app.delete("/Products/{product_id}")
def delete_product(product_id: int):
    for i in range(len(products_db)):
        if products_db[i]["id"] == product_id:
            products_db.pop(i)
            return {"Data": "Deleted"}
    return {"Data": "Not found"}
