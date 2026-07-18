from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
db_url = "postgresql://sri:12369@127.0.0.1:5432/backend_proj"
engine = create_engine(db_url)
Session = sessionmaker(autocommit=False, autoflush=False, bind=engine)